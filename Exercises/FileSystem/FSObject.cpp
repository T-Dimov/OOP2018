#include "stdafx.h"

#include "FSObject.h"

#include <iostream>

using namespace std;

FSObject::FSObject(const char * name_, size_t size_):name(nullptr)
{
	setName(name_);
	setSize(size_);
}

FSObject::FSObject(const FSObject & other):FSObject(other.name,other.size)
{
}

FSObject & FSObject::operator=(const FSObject & rhs)
{
	if (this != &rhs)
	{
		setName(rhs.name);
		setSize(rhs.size);
	}
	return *this;
}

FSObject::~FSObject()
{
	delete[] name;
}

const char * FSObject::getName() const
{
	return name;
}

int FSObject::getSize() const
{
	return size;
}

void FSObject::setName(const char * newName)
{
	if (newName == nullptr)
		newName = "";
	delete[] name;
	int len = strlen(newName) + 1;
	name = new char[len];
	strcpy_s(name, len, newName);
}

void FSObject::setSize(size_t newSize)
{
	size = newSize;
}

void FSObject::info(size_t indent = 0) const
{
	for (size_t i = 0; i < indent * 4; i++)
	{
		cout << ' ';
	}

	cout << "Size: " << getSize() << "B\t" << getName();
}
