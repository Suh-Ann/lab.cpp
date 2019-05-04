#pragma once

#include "pch.h"

#include <iostream>
#include <cstring>
#include <cstdlib>

using std::swap;

class MyString
{
public:
	MyString();										//конструктор по умолчанию
	MyString(const MyString &string);				//конструктор копирования [MyString copyString(string);]
	MyString(const char* string);					//конструктор копирования [MyString copyString(string);]



	MyString	reverse();							
	unsigned	size();								
	bool		isEmpty();						
	void		print();



	~MyString();									//деструктор

private:
	char *			_data;
	unsigned int	_size;
};



MyString::MyString() :
	_size(0)
{
	std::cout << "Basic constructor" << std::endl;
	_data = new char[1];
	_data[0] = '\0';
}

MyString::~MyString() {
	std::cout << "Destructor" << std::endl;
	delete[] _data;
}

MyString::MyString(const MyString &string) {
	std::cout << "Copy constructor" << std::endl;
	_size = string._size;
	_data = new char[_size + 1];
	strcpy(_data, string._data);
}

MyString::MyString(const char* string) {
	_size = strlen(string);
	_data = new char[_size + 1];
	strcpy(_data, string);
}


unsigned MyString::size() {
	return _size;
}

void MyString::print() {
	std::cout << this->_data << std::endl;

}

bool MyString::isEmpty() {

	return true;
}

int main()
{
	MyString* mystring = new MyString();

	if (mystring->isEmpty())
		std::cout << "Object mystring is empty" << std::endl;
	else
		std::cout << "Object mystring is NOT empty" << std::endl;
	
	MyString* mystringCopy = new MyString("string copy");
	mystringCopy->print();

	MyString* mystringRev = new MyString();


	MyString* mystringCopy2 = new MyString(*mystringRev);

	delete mystring;
	delete mystringCopy;
	delete mystringRev;
	delete mystringCopy2;


}



