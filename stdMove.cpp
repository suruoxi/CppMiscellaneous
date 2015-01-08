/*************************************************************************
    > File Name: stdMove.cpp
    > Author: Peng Zhang
    > Mail: pengzhang_live@live.com 
    > Created Time: 2015-01-08
 ************************************************************************/
/*
 *既然编译器只对右值引用才能调用转移构造函数和转移赋值函数，而所有命名对象都只能是左值引用，如果已知一个命名对象不再被使用而想对它调用转移构造函数和转移赋值函数，也就是把一个左值引用当做右值引用来使用，怎么做呢？标准库提供了函数 std::move，这个函数以非常简单的方式将左值引用转换为右值引用。
 * */
#include<iostream>
using namespace std;
 void ProcessValue(int& i) { 
  std::cout << "LValue processed: " << i << std::endl; 
 } 

 void ProcessValue(int&& i) { 
  std::cout << "RValue processed: " << i << std::endl; 
 } 

 int main() { 
  int a = 0; 
  ProcessValue(a); 
  ProcessValue(std::move(a)); 
 }
