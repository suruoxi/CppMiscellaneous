/*************************************************************************
  > File Name: rvalue_lvalue.cpp
  > Author: Peng Zhang
  > Mail: pengzhang_live@live.com 
  > Created Time: 2015-01-08
 ************************************************************************/
/*
 * 右值和左值
 * */
#include<iostream>
using namespace std;
void process_value(int& i) { 
	std::cout << "LValue processed: " << i << std::endl; 
} 

void process_value(int&& i) { 
	std::cout << "RValue processed: " << i << std::endl; 
} 

void forward_value(int&& i) { 
	process_value(i); 
} 

int main() { 
	int a = 0; 
	process_value(a); 
	process_value(1); 
	forward_value(2);

	return 0;
}
