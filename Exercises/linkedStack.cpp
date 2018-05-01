// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cassert>
#include <iostream>

using namespace std;

struct Node
{
	Node();
	Node(int dat);

	int data;
	Node *next;
};

class Stack
{
public:
	Stack();
	Stack(const Stack &other);
	Stack &operator=(const Stack &other);
	~Stack();

	void push(int);
	int pop();

	size_t getSize() const;
	void print() const;

private:
	void copy(const Stack &other);
	void del();

	size_t size;
	Node *start;
};

Node::Node() :data(0), next(nullptr)
{}

Node::Node(int dat) : data(dat), next(nullptr)
{}

Stack::Stack() :size(0), start(nullptr)
{}

Stack::Stack(const Stack &other)
{
	copy(other);
}

Stack &Stack::operator=(const Stack &other)
{
	if (this != &other)
	{
		del();
		copy(other);
	}
	return *this;
}

Stack::~Stack()
{
	del();
}

void Stack::copy(const Stack &other)
{
	size = other.size;
	Node *temp = other.start;
	if (temp)
	{
		start = new Node(temp->data);
		temp = temp->next;
	}
	Node *curr = start;
	while (temp)
	{
		curr->next = new Node(temp->data);
		temp = temp->next;
		curr = curr->next;
	}
}

void Stack::del()
{
	Node *curr = start;
	Node *next;
	while (curr)
	{
		next = curr->next;
		delete curr;
		curr = next;
	}
}

void Stack::push(int data)
{
	Node *temp = new Node(data);
	temp->next = start;
	start = temp;
	++size;
}

int Stack::pop()
{
	assert(start);
	
	int result = start->data;

	Node *temp = start;
	start = start->next;
	delete temp;

	--size;

	return result;
}

size_t Stack::getSize() const
{
	return size;
}

void Stack::print() const
{
	Node *curr = start;
	while (curr)
	{
		cout << curr->data << endl;
		curr = curr->next;
	}
}

int main()
{
	Stack st1;
	st1.push(7);
	st1.push(9);
	st1.print();
	st1.push(11);
	st1.push(100);
	st1.print();
	Stack st2(st1);
	st2.pop();
	st2.pop();
	st2.print();
	st1 = st2;
	st1.print();

	cin.get();
    return 0;
}

