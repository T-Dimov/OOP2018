#pragma once
#ifndef FSOBJECT_H
#define FSOBJECT_H

class FSObject
{
public:
	FSObject(const char* name_ = nullptr, size_t size_ = 1);
	FSObject(const FSObject& other);
	FSObject& operator=(const FSObject& rhs);
	~FSObject();

	const char* getName()const;
	int getSize()const;

	void setName(const char* newName);
	void setSize(size_t newSize);
	
	virtual FSObject* clone() const = 0;
	virtual void info(size_t indent = 0) const = 0;
private:
	char* name;
	size_t size;
};

#endif // !FSOBJECT_H
