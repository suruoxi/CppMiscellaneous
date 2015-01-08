/*************************************************************************
  > File Name: rvalueStringNoMove.cpp
  > Author: Peng Zhang
  > Mail: pengzhang_live@live.com 
  > Created Time: 2015-01-08
 ************************************************************************/

/*
 * 这里用到的是c++11的特性
 * http://www.ibm.com/developerworks/cn/aix/library/1307_lisl_c11/
 *
 * 使用右值的move语义，如果传入拷贝构造函数或者赋值构造函数的是右值，那么不需要拷贝，只需要修改指针即可。有几点需要注意
 *
 *1. 参数（右值）的符号必须是右值引用符号，即“&&”。

2. 参数（右值）不可以是常量，因为我们需要修改右值。

3. 参数（右值）的资源链接和标记必须修改。否则，右值的析构函数就会释放资源。转移到新对象的资源也就无效了。
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

		MyString(MyString&& str) { 
			std::cout << "Move Constructor is called! source: " << str._data << std::endl; 
			_len = str._len; 
			_data = str._data; 
			str._len = 0; 
			str._data = NULL; 
		}
		MyString& operator=(MyString&& str) { 
			std::cout << "Move Assignment is called! source: " << str._data << std::endl; 
			if (this != &str) { 
				_len = str._len; 
				_data = str._data; 
				str._len = 0; 
				str._data = NULL; 
			} 
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
