// ConsoleApplication38.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Header.h"
#include <iostream>
#include <string>

using namespace std;

namespace mySpace
{
	class string
	{
	public:
		string();
		string(const char *str_);

		string(const string &other);
		string &operator=(const string& rhs);
		~string();

		friend std::ostream & operator<<(std::ostream &out, const string &str);

	private:
		void copy(const string &other);
		void del();

		char *str;
		size_t size;
		size_t capacity;
	};

	string::string()
	{
		capacity = 1;
		size = 1;
		str = new char[capacity];
		str[0] = '\0';
	}

	string::string(const char *str_)
	{
		capacity = strlen(str_) + 1;
		size = capacity;

		str = new char[capacity];
		strcpy_s(str, capacity, str_);
	}

	string::string(const string &other)
	{
		copy(other);
	}

	string::~string()
	{
		del();
	}

	string& string::operator=(const string &rhs)
	{
		if (this != &rhs)
		{
			del();
			copy(rhs);
		}
		return *this;
	}

	std::ostream &operator<<(std::ostream &out, const string &string)
	{
		out << string.str;

		return out;
	}

	void string::copy(const string &other)
	{
		capacity = other.capacity;
		size = other.size;

		str = new char[capacity];
		strcpy_s(str, size, other.str);
	}

	void string::del()
	{
		delete[] str;
	}
}

using namespace mySpace;

int main()
{
	mySpace::string a, b("gesho"), c("posho");
	std::cout << b << std::endl << c << std::endl;

	std::cin.get();
    return 0;
}

