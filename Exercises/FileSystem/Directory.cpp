#include "stdafx.h"
#include "Directory.h"

#include <iostream>

using namespace std;

Directory::Directory(const char* name_) 
	: FSObject(name_,0)
	, count(0)
	, capacity(20)
	, objects(new FSObject*[capacity])
{}

Directory::Directory(const Directory& other)
	:FSObject(other)
{
	copy(other);
}

Directory& Directory::operator=(const Directory& rhs)
{
	if (this != &rhs)
	{
		FSObject::operator=(rhs);
		del();
		copy(rhs);
	}
	return *this;
}

Directory::~Directory()
{
	del();
}

FSObject* Directory::clone() const
{
	return new Directory(*this);
}

void Directory::info(size_t indent) const
{
	FSObject::info();

	cout << endl;

	for (size_t i = 0; i < count; i++)
	{
		objects[i]->info(indent + 1);
	}
}

void Directory::add(const FSObject* newObject)
{
	if (count == capacity)
		resize();
	objects[count++] = newObject->clone();
}

void Directory::copy(const Directory& other)
{
	count = other.count;
	capacity = other.capacity;

	objects = new FSObject*[capacity];

	for (size_t i = 0; i < count; i++)
	{
		objects[i] = other.objects[i]->clone();
	}
}

void Directory::del()
{
	for (size_t i = 0; i < count; i++)
	{
		delete objects[i];
	}

	delete[] objects;
}

void Directory::resize()
{
	capacity += 10;
	FSObject** newArr = new FSObject*[capacity];

	for (size_t i = 0; i < count; i++)
	{
		newArr[i] = objects[i];
	}

	delete[] objects;
	objects = newArr;
}
