#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
struct Node
{
	Node(const T &data_, Node<T> *next_ = nullptr);

	T data;
	Node<T> *next;
};

template <typename T>
class LinkedList
{
public:
	LinkedList();
	LinkedList(const LinkedList<T> &other);
	LinkedList<T> &operator=(const LinkedList<T> &other);
	~LinkedList();

	void push_front(const T &elem);
	void push_back(const T &elem);
	void insert(Node<T> *prev, const T &elem);

	T front() const;
	T back() const;
	T at(size_t index) const;

	T pop_front();
	T pop_end();
	T pop_at(size_t index);

	size_t size() const;
	bool empty() const;

private:
	void copy(const LinkedList<T> &other);
	void del();
	Node<T> *start;
	Node<T> *end;
	size_t size_;
};

#include "LinkedList.inl"

#endif