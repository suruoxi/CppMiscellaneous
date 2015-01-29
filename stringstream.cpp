/*************************************************************************
    > File Name: stringstream.cpp
    > Author: Peng Zhang
    > Mail: pengzhang_live@live.com 
    > Created Time: 2015-01-29
 ************************************************************************/

#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main(){
	//测试发现，默认是支持读写的
	//std::stringstream ss;
	//std::stringstream ss(stringstream::in | stringstream::out);
	// 不支持输出
	std::stringstream ss(stringstream::in );
	ss << 100 <<' '<<200;
	int foo, bar;
	ss >> foo >> bar;

	std::cout << "foo: " << foo << '\n';
	std::cout << "bar: " << bar <<'\n';


	return 0;
}
