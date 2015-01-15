/*************************************************************************
    > File Name: negativeArrayIndex.cpp
    > Author: Peng Zhang
    > Mail: pengzhang_live@live.com 
    > Created Time: 2015-01-15
 ************************************************************************/
// 想到二等功名数组是作为指针的，也就可以忍了
#include<iostream>
using namespace std;
int main(){
	int A[] = {
		1,2,3,4,5,6
	};
	int *arr = A+3;
	cout<<arr[-3]<<endl
		<<arr[-2]<<endl
		<<arr[-1]<<endl
		<<arr[0]<<endl
		<<arr[1]<<endl
		<<arr[2]<<endl;

	return 0;
}
