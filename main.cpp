#include <iostream>
#include "12.hpp"

int main()
{
	std::cout << "Start\n";
	String test1;
	String test2;
	char text[] = "Hello ";

	std::cout << "Insert test1\n";
	test1.insert('d');
	test1.print();

	std::cout << "Add string test2\n";
	test2.add_string(text);
	test2.print();

	std::cout << "Remove test2\n";
	test2.remove(2, 4);
	test2.print();
	
	std::cout << "test3 = test1\n";
	String test3 = test1;
	test3.print();

	std::cout << "test3 conc test2\n";
	test3.conc(test2);
	test3.print();
	return 0;
}
