// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>

using namespace std;

//void print(int number)
//{
//	cout << number << endl;
//}

void print(double number)
{
	cout << number << endl;
}

//void print(const char *str)
//{
//	cout << str << endl;
//}

template<typename T>
void print(const T &data)
{
	cout << data << endl;
}

//template<typename T, typename U, typename V>
//void print(const T &data0, const U &data1, const V &data2)
//{
//	cout << data0 << endl;
//	cout << data1 << endl;
//	cout << data2 << endl;
//}

template<typename First, typename... Ts>
void print(const First &first, const Ts&... data)
{
	print(first);
	print(data...);
}

int main()
{
	/*print(5);
	print(3.14);
	print("kon");*/

	print(5, 3.14, "kon");

	stack<int> st;
	//print(st);

	cin.get();
    return 0;
}

