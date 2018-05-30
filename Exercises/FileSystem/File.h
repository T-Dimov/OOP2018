#pragma once
#ifndef FILE_H
#define FILE_H
#include "FSObject.h"

class File:public FSObject
{
public:
	File(const char* name_, size_t size_, const char* extension_);
	File(const File& other);
	File& operator=(const File& rhs);
	~File();

	const char* getExtension()const;

	FSObject* clone() const override;
	void info(size_t indent = 0) const override;

private:
	char* extension;
	void setExtension(const char* newName);
};

#endif // !FILE_H
