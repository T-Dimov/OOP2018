#include <iostream>

using namespace std;

class Base1
{
public:
	Base1(double val = 1.0);
	~Base1();

protected:
	double b1;
};

Base1::Base1(double val) : b1(val)
{
	cout << "Base1()" << endl;
}

Base1::~Base1()
{
}

class Base2 : public Base1
{
public:
	Base2(double val = 2.0);
	~Base2();

protected:
	double b2;
};

Base2::Base2(double val) : b2(val)
{
	cout << "Base2()" << endl;
}

Base2::~Base2()
{
}

class Base3 : public Base1
{
public:
	Base3(double val = 3.0);
	~Base3();

protected:
	double b3;
	//Base2 base2;
};

Base3::Base3(double val) : b3(val), Base1(val)
{
	cout << "Base3()" << endl;
}

Base3::~Base3()
{
}

class Derived : public Base2, Base3
{
public:
	Derived(double val = 3.0);
	~Derived();

protected:
	double d;
};

Derived::Derived(double val) : d(val), Base3(val)
{
}

Derived::~Derived()
{
	cout << Base1::b1 << endl;
	cout << Base1::b1 << endl;
	cout << Base2::b1 << endl;
	cout << Base3::b1 << endl;
}

int main()
{
	/*Base1 base1;
	Base2 base2;*/
	{Derived der; }

	cin.get();
	return 0;
}