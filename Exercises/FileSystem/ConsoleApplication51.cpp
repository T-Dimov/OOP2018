// ConsoleApplication51.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "File.h"
#include "Directory.h"

#include <iostream>

using namespace std;

int main()
{
	Directory dir("test");
	
	File fn("test file", 16, "txt");

	Directory dir2("dir 2");

	dir2.add(&fn);

	dir.add(&dir2);

	dir.info();

	cin.get();
	return 0;
}