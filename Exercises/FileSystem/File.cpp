#include "stdafx.h"

#include "File.h"

#include <iostream>

using namespace std;

File::File(const char* name_, size_t size_, const char* extension_)
	: FSObject(name_,size_)
	, extension(nullptr)
{
	setExtension(extension_);
}

File::File(const File& other)
	: FSObject(other)
	, extension(nullptr)
{
	setExtension(other.extension);
}

File& File::operator=(const File& rhs)
{
	if (this != &rhs)
	{
		FSObject::operator=(rhs);
		setExtension(rhs.extension);
	}
	return *this;
}

File::~File()
{
	delete[] extension;
}


const char* File::getExtension() const
{
	return extension;
}

void File::setExtension(const char* newName)
{
	if (newName == nullptr)
		newName = "";
	delete[] extension;
	int len = strlen(newName) + 1;
	extension = new char[len];
	strcpy_s(extension, len, newName);
}
FSObject* File::clone() const
{
	return new File(*this);
}

void File::info(size_t indent) const
{
	FSObject::info();
	cout << '.' << getExtension() << endl;
}