// ConsoleApplication43.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class RegularShape
{
public:
	RegularShape(string name_, size_t sideLenght = 1)
	{
		name = name_;
		side = sideLenght;
	}

	friend ostream &operator<<(ostream &out, const RegularShape &shape);

protected:
	string name;
	double side;
};

ostream &operator<<(ostream &out, const RegularShape &shape)
{
	out << "name: " << shape.name << endl;
	out << "side: " << shape.side << endl;
	return out;
}

class Rectangle : public RegularShape
{
public:
	Rectangle(string name_, size_t sideLenght = 1) :RegularShape(name_, sideLenght)
	{}

	friend ostream &operator<<(ostream &out, const Rectangle &shape);

	double area()
	{
		return side * side;
	}
};

ostream &operator<<(ostream &out, const Rectangle &shape)
{
	out << "type: Rectangle" << endl;
	out << dynamic_cast<const RegularShape&>(shape);
	return out;
}

class Triangle : public RegularShape
{
public:
	Triangle(string name_, size_t sideLenght = 1) :RegularShape(name_, sideLenght)
	{}

	friend ostream &operator<<(ostream &out, const Triangle &shape);

	double area()
	{
		return sqrt(3) * side * side / 4;
	}
};

ostream &operator<<(ostream &out, const Triangle &shape)
{
	out << "type: Triangle" << endl;
	out << dynamic_cast<const RegularShape&>(shape);
	return out;
}

int main()
{
	RegularShape fig("pesho");
	cout << fig << endl;

	Rectangle rec("gosho");
	cout << rec;
	cout << "area: " << rec.area() << endl << endl;

	Triangle tri("misho");
	cout << tri;
	cout << "area: " << tri.area() << endl;

	cin.get();
    return 0;
}

