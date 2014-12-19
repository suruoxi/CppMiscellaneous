/*************************************************************************
    > File Name: Print1To1000.cpp
    > Author: Peng Zhang
    > Mail: pengzhang_live@live.com 
    > Created Time: 2014-12-08
 ************************************************************************/
/*
 *http://coolshell.cn/articles/3445.html
请把从1到1000的数打印出来，但你不能使用任何的循环语句或是条件语句。更不能写1000个printf或是cout。用C/C++语言
 */ 
/*
 * 还有模板偏特化等方式可用
 */ 
#include<iostream>
using namespace std;

class Printer{
public:
	Printer(){
		static unsigned i = 1;
		cout<< i++ <<endl;
	}
};

int main(){
	Printer p[1000];
	return 0;
}
