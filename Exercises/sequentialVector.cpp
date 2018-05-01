// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

template<typename T>
class Vector
{
public:
	Vector();
	Vector(const Vector<T> &other);
	Vector<T> &operator=(const Vector<T> &other);
	~Vector();

	size_t insert(const T &elem, size_t index = this->size);

private:
	void copy(const Vector &other);
	void del();
	void resize(size_t index);

	T *data;
	size_t size;
	size_t capacity;
};

template<typename T>
Vector<T>::Vector()
{
	capacity = 10;
	size = 0;
	data = new T[capacity];
}

template<typename T>
Vector<T>::Vector(const Vector<T> &other)
{
	copy(other);
}

template<typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}
	return *this;
}

template<typename T>
Vector<T>::~Vector()
{
	del();
}

template<typename T>
void Vector<T>::copy(const Vector<T> &other)
{
	size = other.size;
	capacity = other.capacity;
	data = new T[capacity];
	for (size_t i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

template<typename T>
void Vector<T>::del()
{
	delete[] data;
}

template<typename T>
size_t Vector<T>::insert(const T &elem, size_t index)
{
	if (index > size)
		index = size;

	if (size == capacity)
	{
		resize(index);
	}
	else
	{
		for (size_t i = size; i > index; i--)
		{
			data[i] = data[i - 1];
		}
	}

	data[index] = elem;

	++size;

	return index;
}

template<typename T>
void Vector<T>::resize(size_t index)
{
	capacity *= 2;
	T *temp = new T[capacity];
	for (size_t i = 0; i < index; i++)
	{
		temp[i] = data[i];
	}
	for (size_t i = index + 1; i < size; i++)
	{
		temp[i] = data[i];
	}
	delete[] data;
	data = temp;
}

int main()
{
	Vector<int> a;
	Vector<char> b;
	a.insert(52, 13);
	a.insert(13, 0);
	cin.get();
    return 0;
}

