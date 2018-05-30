#pragma once
#ifndef DIRECTORY_H
#define DIRECTORY_H
#include "File.h"
class Directory : public FSObject
{
public:
	Directory(const char* name_);
	Directory(const Directory& other);
	Directory& operator=(const Directory& rhs);
	~Directory();

	FSObject* clone() const override;
	void info(size_t indent = 0) const override;

	void add(const FSObject* newObject);

private:
	size_t count, capacity;
	FSObject** objects;

	void copy(const Directory& other);
	void del();
	void resize();
};

#endif // !DIRECTORY_H
