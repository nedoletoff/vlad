#include "12.hpp"
#include <iostream>
#include <cstring>

String::String()
{
	size = 0;
	string = NULL;
}

String::~String()
{
	delete[] string;
}

String::String(String& a)
{
	size = a.size;
	string = new char[size];
	for (int i = 0; i < size; ++i)
		string[i] = a.string[i];
}

String& String::operator=(String& a)
{
	if (&a == this)
		return *this;

	size = a.size;
	string = new char[size];
	for (int i = 0; i < size; ++i)
		string[i] = a.string[i];
	return *this;
}

int String::len()
{
	return size;
}

int String::add_string(char* str)
{
//	std::cout << "add string started\n";
	char* temp = new char[size];
	int s = size;
	for (int i = 0; i < s; ++i)
		temp[i] = string[i];

	size += strlen(str) + 1;
	std::cout << size << " " << temp << "\n";
	std::cout << size << " " << str << "\n\n\n";
	delete [] string;
	string = new char[size];

	for (int i = 0; i < s; ++i)
		string[i] = temp[i];
	for (int i = s; i < size; ++i)
		string[i] = str[i - size];
	std::cout << string;
	delete [] temp;
//	std::cout << "add string done\n";
	return 0;

}

int String::remove(int f, int l)
{
	if  (!((l > f) && l < size))
		return -1;

	size = size - l + f;
	char* temp = new char[size];
	for (int i = 0; i < size; ++i)
		if (i >= f && i < l)
			continue;
		else
			temp[i] = string[i];
	delete [] string;
	
	string = new char[size];

	for (int i = 0; i < size; ++i)
		string[i] = temp[i];
	delete [] temp;
	return 0;

}

int String::remove(int n)
{
	if (n < 0 || n >= size)
		return 1;
	char* temp = new char[size - 1];
	for (int i = 0; i < size; ++i)
		if (i != n)
			temp[i] = string[i];
	delete [] string;
	--size;
	string = new char[size];
	for (int i = 0; i < size; ++i)
		string[i] = temp[i];
	delete [] temp;
	return 0;
}


void String::insert(char st)
{
	char* temp = new char [++size];
	for (int i = 0; i < size - 1; ++i)
		temp[i] = string[i];
	temp[size] = st;
	delete [] string;
	string = new char[size];
	for (int i = 0; i < size; ++i)
		string[i] = temp[i];
	delete [] temp;
}

void String::conc(String& p)
{
//	while (size && string[size-1] == '\0')
//		remove(size-1);
	add_string(p.string);
}

void String::print()
{
	for (int i = 0; i < size; ++i)
	       std::cout << string[i];
	std::cout << '\n';	
}
