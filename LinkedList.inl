#ifndef LINKEDLIST_INL
#define LINKEDLIST_INL

#include <cassert>
#include "LinkedList.h"

template <typename T>
Node<T>::Node(const T &data_, Node<T> *next_ /*= nullptr*/) : next(next_), data(data_)
{}

template <typename T>
LinkedList<T>::LinkedList()
{
	start = nullptr;
	end = nullptr;
	size_ = 0;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &other)
{
	copy(other);
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}
	return *this;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	del();
}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T> &other)
{
	size_ = other.size_;

	start = nullptr;

	Node<T> *temp = other.start;

	if (temp)
	{
		start = new Node<T>(temp->data);
		temp = temp->next;
	}

	Node<T> *curr = start;

	while (temp)
	{
		curr->next = new Node<T>(temp->data);
		curr = curr->next;
		temp = temp->next;
	}

	end = curr;
}

template <typename T>
void LinkedList<T>::del()
{
	Node<T> *temp;
	while (start)
	{
		temp = start->next;
		delete start;
		start = temp;
	}
}

template <typename T>
void LinkedList<T>::push_front(const T &elem)
{
	Node<T> *temp = new Node<T>(elem, start);
	start = temp;
	size_++;
	if (size_ == 1)
	{
		end = start;
	}
}

template<typename T>
void LinkedList<T>::push_back(const T &elem)
{
	Node<T> *temp = new Node<T>(elem);
	size_++;
	if (end)
	{
		end->next = temp;
	}
	else
	{
		start = temp;
	}
	end = temp;
}

template<typename T>
void LinkedList<T>::insert(Node<T> *prev, const T &elem)
{
	bool correct = false;
	Node<T> *curr = start;
	while (curr && !correct)
	{
		correct = curr == prev;
		curr = curr->next;
	}

	if (correct)
	{
		Node<T> *temp = new Node<T>(elem);
		temp->next = prev->next;
		prev->next = temp;
		if (prev == end)
		{
			end = temp;
		}
		size_++;
	}
	else
	{
		push_back(elem);
	}
}

template<typename T>
T LinkedList<T>::front() const
{
	assert(start);
	return start->data;
}

template<typename T>
T LinkedList<T>::back() const
{
	assert(end);
	return end->data;
}

template<typename T>
T LinkedList<T>::at(size_t index) const
{
	if (index < size_)
	{
		Node<T> *curr = start;
		Node<T> *prev;
		for (size_t i = 0; i < index && curr; i++, curr = curr->next)
		{
			prev = curr;
		}

		assert(prev);
		return prev->data;
	}
	else
	{
		return back();
	}
}

template <typename T>
T LinkedList<T>::pop_front()
{
	assert(start);
	Node<T> *temp = start;
	start = start->next;

	T result = temp->data;
	delete temp;
	size_--;

	if (size_ == 0)
	{
		end = nullptr;
	}

	return result;
}

template<typename T>
T LinkedList<T>::pop_end()
{
	return T();
}

template<typename T>
T LinkedList<T>::pop_at(size_t index)
{
	return T();
}

template <typename T>
size_t LinkedList<T>::size() const
{
	return size_;
}

template <typename T>
bool LinkedList<T>::empty() const
{
	return size_ == 0;
}

#endif