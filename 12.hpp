#pragma once

class String
{
	private:
		char* string;
		int size;
	public:
		String();
		~String();
		String(String&);
		String& operator=(String&);

		int len();
		int add_string(char* str, int str_size = -1);
		int remove(int, int);
		int remove(int);
		void print();
		void insert(char);
		void conc(String&);
};
