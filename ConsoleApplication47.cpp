// ConsoleApplication47.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
class Test
{
public:
	Test(const T& src)
	{
		data = src;
	}

	template <typename U>
	friend ostream& operator<<(ostream& out, const Test<U>& test);

private:
	T data;
};

template <typename T>
ostream& operator<<(ostream& out, const Test<T>& test)
{
	out << test.data;
	return out;
}

class Base
{
public:
	void whoAmI() const
	{
		cout << "Base" << endl;
	}

	virtual void whoAmIReally() const
	{
		cout << "Base" << endl;
	}

	void printVTable() const
	{
		size_t size = sizeof(Base);
		void* start = (void*)this;
		void* field = (void*)&b;
		void* VTable = start;

		cout << "this: " << start << endl;
		cout << "&b: " << field << endl;
		//cout << "VTable: " << VTable << endl;
		cout << endl;
	}

protected:
	int b;
};

class Derived1 : virtual public Base
{
public:
	void whoAmI() const
	{
		cout << "Derived1" << endl;
	}

	void whoAmIReally() const override
	{
		cout << "Derived1" << endl;
	}

	void printVTable() const
	{
		size_t size = sizeof(Derived1);
		void* start = (void*)this;
		void* field = (void*)&b;
		void* VTable = start;

		cout << "this: " << start << endl;
		cout << "&b: " << field << endl;
		cout << "&d1: " << (void*)&d1 << endl;
		//cout << "VTable: " << VTable << endl;
		cout << endl;
	}

protected:
	int d1;
};

class Derived2 : virtual public Base
{
public:
	void whoAmI() const
	{
		cout << "Derived2" << endl;
	}

	void whoAmIReally() const override
	{
		cout << "Derived2" << endl;
	}

	void printVTable() const
	{
		size_t size = sizeof(Derived2);
		void* start = (void*)this;
		void* field = (void*)&b;
		void* VTable = start;

		cout << "this: " << start << endl;
		cout << "&b: " << field << endl;
		cout << "&d2: " << (void*)&d2 << endl;
		//cout << "VTable: " << VTable << endl;
		cout << endl;
	}

protected:
	int d2;
};

class Deriveded : public Derived1, public Derived2
{
public:
	void whoAmI() const
	{
		cout << "Deriveded" << endl;
	}

	void whoAmIReally() const override
	{
		cout << "Deriveded" << endl;
	}

	void printVTable() const
	{
		//size_t size = sizeof(Deriveded);
		//void* VTable = start;

		cout << "this: " << (void*)this << endl;
		cout << "&b: " << (void*)&b << endl;
		cout << "&d1: " << (void*)&d1 << endl;
		cout << "&dd: " << (void*)&dd << endl;
		cout << "&d2: " << (void*)&d2 << endl;
		//cout << "VTable: " << VTable << endl;
		cout << endl;
	}

private:
	int dd;
};

void printCast(const Base* object)
{
	/*object->whoAmI();
	object->whoAmIReally();*/
	object->printVTable();
	cout << sizeof(*object) << endl;
}

void printCast(const Derived1* object)
{
	object->printVTable();
	cout << sizeof(*object) << endl;
}

void printCast(const Derived2* object)
{
	object->printVTable();
	cout << sizeof(*object) << endl;
}

void printCast(const Deriveded* object)
{
	object->printVTable();
	cout << sizeof(*object) << endl;
}

int main()
{
	//Test<int> testche(5);
	//cout << testche << endl;

	/*Base b;
	b.whoAmI();
	b.whoAmIReally();
	cout << endl;

	Derived1 d;
	d.whoAmI();
	d.whoAmIReally();
	cout << endl;

	Base& ref = d;
	ref.whoAmI();
	ref.whoAmIReally();
	cout << endl;

	Derived1& dref = d;
	dref.whoAmI();
	dref.whoAmIReally();
	cout << endl;

	Deriveded dd;
	dd.whoAmI();
	dd.whoAmIReally();
	cout << endl;

	Base& ddref = dd;
	ddref.whoAmI();
	ddref.whoAmIReally();
	cout << endl;

	Derived1& drefd = dd;
	drefd.whoAmI();
	drefd.whoAmIReally();
	cout << endl;*/

	cout << sizeof(void *) << endl;
	cout << sizeof(Base) << endl;
	cout << sizeof(Derived1) << endl;
	cout << sizeof(Derived2) << endl;
	cout << sizeof(Deriveded) << endl;
	cout << endl;

	Base b;
	//b.printVTable();
	//cout << endl;

	Derived1 d1;
	/*d.printVTable();
	cout << endl;*/

	Derived2 d2;

	Deriveded dd;
	//dd.printVTable();

	/*printWhoAmI(&b);
	printWhoAmI(&d1);
	printWhoAmI(&d2);*/
	printCast((Base*)&dd);
	printCast((Derived1*)&dd);
	printCast((Derived2*)&dd);
	printCast(&dd);
	printCast(&d1);

	cin.get();
    return 0;
}

