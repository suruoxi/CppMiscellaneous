/*************************************************************************
    > File Name: BranchPrediction.cpp
    > Author: Peng Zhang
    > Mail: pengzhang_live@live.com 
    > Created Time: 2014-12-08
 ************************************************************************/
/*
 *如果你的data数组是排好序的，那么性能是1.93s，如果没有排序，性能为11.54秒。差5倍多。无论是C/C++/Java，或是别的什么语言都基本上一样。
 *
 *
 * 原因是：分支预测
 * （cuda课学到过，没想到真的能够用到。
 *
 * 分支预测是使用过去的数据，如果排序好了，那么判断语句的结果非常一致，就能获得加速。
 * 若是没有排序，预测随机，代价较大。
 *
 * 方案一：
 * 排序再便利
 *
 * 方案二:
 * 毕竟不是所有情景都是这种判断，通用的做法是取消分支，这样也就不需要预测了。
 * 在本例中，将分支改为：
 *
 * int t = (data[j] - 128) >> 31;
 * sum += ~t & data[j];
 *
 * 基本和排序后再处理一个速度。
 *
 * 另外，在 GCC 下， -O3 或者 -ftree-vectorize参数设定时，gcc会优化分支语句为无分支语句。
 */
#include<iostream>
#include<time.h>
#include<stdlib.h>
const unsigned SIZE = 500000;
using namespace std;


void test1( int arr[], size_t size){
	int sum = 0;
	for(size_t i = 0; i < size; i++){
		if(arr[i] < 4)
			sum += arr[i];
	}
}

void test2(int arr[], size_t size){
	int sum = 0;
	for(size_t i = 0; i < size; i++){
		int t = (arr[i] - 4) >> 31;
		sum += ~t & arr[i];
	}
}

int main(){
	int arr[SIZE];
	srand(time(0));
	for( size_t i = 0; i < SIZE; i++){
		// 位运算比除法效率高 ？？
		arr[i] = rand() & 7;  // only take the last 3 bits 
	}
	
	test1(arr, SIZE);

	return 0;
}
