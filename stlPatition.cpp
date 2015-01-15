/*************************************************************************
    > File Name: stlPatition.cpp
    > Author: Peng Zhang
    > Mail: pengzhang_live@live.com 
    > Created Time: 2015-01-15
 ************************************************************************/

// 
//使用STL的partition函数，将一个数组中的奇数和偶数分开
//partition的作用是，将满足一定条件的元素放到区间的首部，不符合的放到尾部
// 输出是 1,5,3,2,4,6 ，奇数部分和偶数部分的顺序发生了变化 
#include<iostream>
#include<iterator>
#include<algorithm>
using namespace std;

struct IsOdd{
	bool operator()(int x) const{
		return x % 2 != 0; 
	}
};

bool isOdd(int x){
	return x % 2 != 0;
}

int main(){
	int arr[] = {
		1,2,3,4,5,6
	};

	partition(arr, arr+6, IsOdd());
	std::copy(arr, arr+6, std::ostream_iterator<int>(std::cout,","));
	std::cout<<std::endl;
}
