#ifndef STACK_H
#define STACK_H

template <typename T>
struct Node
{
	Node(const T &data_, Node<T> *next_ = nullptr);

	T data;
	Node<T> *next;
};

template <typename T>
class Stack
{
public:
	Stack();
	Stack(const Stack<T> &other);
	Stack<T> &operator=(const Stack<T> &other);
	~Stack();

	void push(const T &elem);
	T pop();

	size_t size() const;
	bool empty() const;

private:
	void copy(const Stack<T> &other);
	void del();
	Node<T> *start;
	size_t size_;
};

#include "Stack.inl"

#endif