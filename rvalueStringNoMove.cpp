/*************************************************************************
  > File Name: rvalueStringNoMove.cpp
  > Author: Peng Zhang
  > Mail: pengzhang_live@live.com 
  > Created Time: 2015-01-08
 ************************************************************************/

/*
 * 一个简单的 String 类实现，在没有使用move语义的时候，即使传入一个右值，也仍然要复制，这中开销是很大的。
 * 如果参数是复杂对象，开销更明显
 * */

#include<iostream>
#include<cstring>
#include<vector>
#include<cstdlib>
using namespace std;

class MyString { 
	private: 
		char* _data; 
		size_t   _len; 
		void _init_data(const char *s) { 
			_data = new char[_len+1]; 
			memcpy(_data, s, _len); 
			_data[_len] = '\0'; 
		} 
	public: 
		MyString() { 
			_data = NULL; 
			_len = 0; 
		} 

		MyString(const char* p) { 
			_len = strlen (p); 
			_init_data(p); 
		} 

		MyString(const MyString& str) { 
			_len = str._len; 
			_init_data(str._data); 
			std::cout << "Copy Constructor is called! source: " << str._data << std::endl; 
		} 

		MyString& operator=(const MyString& str) { 
			if (this != &str) { 
				_len = str._len; 
				_init_data(str._data); 
			} 
			std::cout << "Copy Assignment is called! source: " << str._data << std::endl; 
			return *this; 
		} 

		virtual ~MyString() { 
			if (_data) free(_data); 
		} 
}; 

int main() { 
	MyString a; 
	a = MyString("Hello"); 
	std::vector<MyString> vec; 
	vec.push_back(MyString("World")); 
}
