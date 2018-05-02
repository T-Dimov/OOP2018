#include <iostream>
#include <string>

using namespace std;

class RegularShape
{
public:
	RegularShape(string name_, double sideLenght = 1)
	{
		name = name_;
		side = sideLenght;
	}

	friend ostream &operator<<(ostream &out, const RegularShape &shape);

	double perimeter() const
	{
		return 0 * side;
	}

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

class Square : public RegularShape
{
public:
	Square(string name_, double sideLenght = 1) :RegularShape(name_, sideLenght)
	{
		sideMod = 1;
	}

	friend ostream &operator<<(ostream &out, const Square &shape);

	double area() const
	{
		return side * side;
	}

	double perimeter() const
	{
		return 4 * side + sideMod;
	}

private:
	double sideMod;
};

ostream &operator<<(ostream &out, const Square &shape)
{
	out << "type: Square" << endl;
	out << dynamic_cast<const RegularShape&>(shape);
	return out;
}

class Triangle : public RegularShape
{
public:
	Triangle(string name_, double sideLenght = 1) :RegularShape(name_, sideLenght)
	{}

	friend ostream &operator<<(ostream &out, const Triangle &shape);

	double area() const
	{
		return sqrt(3) * side * side / 4;
	}

	double perimeter() const
	{
		return 3 * side;
	}
};

ostream &operator<<(ostream &out, const Triangle &shape)
{
	out << "type: Triangle" << endl;
	out << dynamic_cast<const RegularShape&>(shape);
	return out;
}

double getPerimeter(const Square &shape)
{
	return shape.perimeter();
}

double getPerim(const void *shape)
{
	return ((Square *)shape)->perimeter();
}

//int main()
//{
//	RegularShape fig("pesho");
//	cout << fig << endl;
//	cout << "perimeter: " << fig.perimeter() << endl << endl;
//
//	Square rec("gosho", 3.14);
//	cout << rec;
//	cout << "area: " << rec.area() << endl << endl;
//	cout << "perimeter: " << rec.perimeter() << endl << endl;
//
//	Triangle tri("misho");
//	cout << tri;
//	cout << "area: " << tri.area() << endl;
//	cout << "perimeter: " << tri.perimeter() << endl << endl;
//
//	RegularShape &reg = rec;
//	//cout << "perimeter: " << reg.perimeter() << endl << endl;
//
//	cout << "perim: " << getPerimeter(rec) << endl;
//
//	cout << "per: " << getPerim(&rec);
//	
//	RegularShape *pReg = &tri;
//
//	cout << "per: " << getPerim(&tri);
//
//
//
//	cin.get();
//	return 0;
//}