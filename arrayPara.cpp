/*************************************************************************
    > File Name: arrayPara.cpp
    > Author: Peng Zhang
    > Mail: pengzhang_live@live.com 
    > Created Time: 2015-01-15
 ************************************************************************/

#include<iostream>
using namespace std;

int arraySize( int arr[]){
	return sizeof(arr);
}

int arraySize1(int *arr){
	return sizeof(arr);
}

int main(){
	int array[] = {
		1,2,3,4,5,6,7,8,9
	};

	cout<<sizeof(array)<<endl
		<<arraySize(array)<<endl
		<<arraySize1(array)<<endl;

	return 0;
}
