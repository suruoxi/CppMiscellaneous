/*************************************************************************
    > File Name: NullPointerCallStaticMethod.cpp
    > Author: Peng Zhang
    > Mail: pengzhang_live@live.com 
    > Created Time: 2014-12-09
 ************************************************************************/
// http://coolshell.cn/articles/2053.html
// 使用空指针调用静态函数   难道又是设计漏洞？？

#include<iostream>
using namespace std;

class Foo{
public:
	static void bar(){
		std::cout<<"bar()"<<std::endl;
	}
};

int main(){
	Foo *foo = NULL;
	foo->bar();// =>  WTF !?
	return 0;
}
