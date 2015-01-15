/*************************************************************************
  > File Name: itoaImplementation.cpp
  > Author: Peng Zhang
  > Mail: pengzhang_live@live.com 
  > Created Time: 2015-01-15
 ************************************************************************/
// By Matthew Wilson , http://synesis.com.au/publications.html
#include<iostream>
#include<algorithm>
using namespace std;

const char* convert(char buf[], int value)
{
	static char digits[19]={
		'9','8','7','6','5','4','3','2','1','0',
		'1','2','3','4','5','6','7','8','9'
	};
	static const char* zero = digits + 9; // zero 指向 ‘0’
	// works for -2147483648 .. 2147483647
	int i = value;
	char* p = buf;
	do {
		// lsd - least significant digit
		int lsd = i % 10; // lsd 可能小于 0
		i /= 10;
		// 是向下取整还是向零取整?
		*p++ = zero[lsd]; // 下标可能为负
	} while (i != 0);
	if (value < 0) {
		*p++ ='-';
	}
	*p = '\0';
	std::reverse(buf, p);
	return p; // p - buf 即为整数长度
}

int main(){
	char buff[32];
	int values[] = {
		1,2432,4556,-2345,2147483647,-2147483648
	};
	for(int i=0; i != 6; ++i){
		convert(buff, values[i]);
		cout<<values[i]<<'\t'<<buff<<endl;
	}

	return 0;
}
