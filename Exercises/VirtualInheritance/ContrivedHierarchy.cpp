#include <iostream>
#include <string>

using namespace std;

class Example
{
public:
	Example(int data_ = 0) : data(data_)
	{
		cout << "Example::Example()\n";
	}

	Example(const Example &other) : data(other.data)
	{
		cout << "Example::Example(const Example &)\n";
	}

	Example &operator=(const Example &rhs)
	{
		if (this != &rhs)
		{
			data = rhs.data;
		}
		return *this;
	}

	~Example()
	{
		cout << "Example::~Example()\n";
	}

	friend ostream &operator<<(ostream &out, const Example &shape);

private:
	int data;
};

ostream &operator<<(ostream &out, const Example &example)
{
	out << "data: " << example.data;
	return out;
}

class RegularShape
{
public:
	RegularShape(const string &name_, double sideLenght = 1) : name(name_)
	{
		cout << "RegularShape::RegularShape()\n";
		side = sideLenght;
	}

	RegularShape(const RegularShape &other) : /*ex(other.ex),*/ name(other.name), side(other.side)
	{
		cout << "RegularShape::RegularShape(const RegularShape &)\n";
	}

	RegularShape &operator=(const RegularShape &rhs)
	{
		if (this != &rhs)
		{
			name = rhs.name;
			side = rhs.side;
			//ex = rhs.ex;
		}
		return *this;
	}

	~RegularShape()
	{
		cout << "RegularShape::~RegularShape()\n";
	}

	friend ostream &operator<<(ostream &out, const RegularShape &shape);

protected:
	string name;
	double side;

	//Example ex;
};

ostream &operator<<(ostream &out, const RegularShape &shape)
{
	out << "name: " << shape.name << endl;
	out << "side: " << shape.side << endl;
	//out << "ex: " << shape.ex;
	return out;
}

class Rectangle : virtual public RegularShape
{
public:
	Rectangle(const string &name_, double sideLenght = 1) : /*ex2(),*/ RegularShape(name_, sideLenght)
	{
		cout << "Rectangle::Rectangle()\n";
	}

	Rectangle(const Rectangle &other) : /*ex2(other.ex2),*/ RegularShape(other)
	{
		cout << "Rectangle::Rectangle(const Rectangle &)\n";
	}

	Rectangle &operator=(const Rectangle &rhs)
	{
		if (this != &rhs)
		{
			RegularShape::operator=(rhs);
			//ex2 = rhs.ex2;
		}
		return *this;
	}

	~Rectangle()
	{
		cout << "Rectangle::~Rectangle()\n";
	}

	friend ostream &operator<<(ostream &out, const Rectangle &shape);

	double area()
	{
		return side * side;
	}

private:
	//Example ex2;
};

ostream &operator<<(ostream &out, const Rectangle &shape)
{
	out << "type: Rectangle" << endl;
	out << dynamic_cast<const RegularShape&>(shape) << endl;
	//out << shape.ex2;
	return out;
}

class Triangle : public RegularShape
{
public:
	Triangle(const string &name_, double sideLenght = 1) : RegularShape(name_, sideLenght)
	{
		cout << "Triangle::Triangle()\n";
	}

	Triangle(const Triangle &other) : RegularShape(other)
	{
		cout << "Triangle::Triangle(const Triangle &)\n";
	}

	Triangle &operator=(const Triangle &rhs)
	{
		if (this != &rhs)
		{
			Triangle::operator=(rhs);
		}
		return *this;
	}

	~Triangle()
	{
		cout << "Triangle::~Triangle()\n";
	}

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

class Square : public Rectangle, virtual Triangle
{
public:
	Square(const string &name_, double sideLenght = 1) : Rectangle(name_, sideLenght), Rectangle::RegularShape(name_, sideLenght), Triangle(name_, sideLenght * 10)
	{
		//RegularShape();
		//Triangle();
		//Rectangle();
		cout << "Square::Square()\n";
	}

	Square(const Square &other)
		: Rectangle(other)
		, Rectangle::RegularShape(Rectangle(other))
		, Triangle(other)
	{
		//Rectangle(&Rectangle); temporary
		//RegularShape(&RegularShape);	virtual
		//Triangle(&Triangle);	virtual
		//Rectangle(&Rectangle);
		cout << "Square::Square(const Square &)\n";
	}

	Square &operator=(const Square &rhs)
	{
		if (this != &rhs)
		{
			Rectangle::operator=(rhs);
		}
		return *this;
	}

	~Square()
	{
		cout << "Square::~Square()\n";
	}

	friend ostream &operator<<(ostream &out, const Square &shape);

private:

};

ostream &operator<<(ostream &out, const Square &shape)
{
	out << "type: Square" << endl;
	out << dynamic_cast<const Rectangle&>(shape);
	return out;
}

int main()
{
	{
		RegularShape fig("pesho");
		//cout << fig << endl << endl;

		cout << endl;

		Rectangle rec("gosho");
		//cout << rec << endl;
		//cout << "area: " << rec.area() << endl << endl;

		cout << endl;

		Triangle tri("misho");
		//cout << tri << endl;
		//cout << "area: " << tri.area() << endl << endl;

		cout << endl;

		Square	sq("olaf");

		cout << endl;

		Square	sq2 = sq;

		cout << endl;

		//cout << sq2 << endl << endl;

		sq = sq2;

		cout << endl;
		//cout << sq2 << endl << endl;
	}

	cin.get();
	return 0;
}
