/*************************************************************************
    > File Name: efficiency.cpp
    > Author: Peng Zhang
    > Mail: pengzhang_live@live.com 
    > Created Time: 2015-01-06
 ************************************************************************/

/*
 * 用到了两种优化策略
 * 一， 判断一个数字 c 是否在 a、b之间。 一般使用 c >= a && c <= b， 是多条CPU指令。优化方式为，计算 (c-a) < (b-a)，b-a可以提前算好。 (unsigned)(c-a) <(b-a) 等价于前面的判断。c在 a b之间时，结果最高为为1 （负），否则为0. 而如果 c-a 为负，负值作为unsigned来读，比所有正值都大，所以结果仍然正确 unsign操作本身没有负担（数据没变，只是怎么读而已）
 * 二， 消除分支，减少分支预测的开销
 *
 * 由于本例中 a=0， 结果更加简单。
 *
 * 大致有两三倍的速度差别（如果能去掉循环体的时间，比率会更高）
 * 但是： 一个 -O3选项，时间立刻变一样了。（好像vs还不支持分支预测的消除）
 */ 

#include<iostream>
#include<time.h>
#include<sys/time.h>
#include<stdlib.h>

const int SIZE = 30000;
const int N=100;
int arr[SIZE];

using namespace std;

int main(){

	struct timeval t1,t2;

	srand(time(0));
	for(int i=0; i != SIZE; ++i){
		arr[i] = rand()%512 - 256;
	}
	// 最初版本
	gettimeofday(&t1,0);
	for(int j=0; j != SIZE; ++j){
		arr[j] = ( arr[j] >0 && arr[j] < 256) ? arr[j] : 0;
	}
	gettimeofday(&t2,0);

	double time1 = (t2.tv_sec - t1.tv_sec)*1000000 + (t2.tv_usec-t1.tv_usec);


	for(int i=0; i != SIZE; ++i){
		arr[i] = rand()%512 - 256;
	}
	// 优化版本
	gettimeofday(&t1,0);
	for(int j=0; j != SIZE; ++j){
		// 移位取得最高为， 避免将bool转化为int
		arr[j] = ~((arr[j] - 256) >> 31) & arr[j];
	}
	gettimeofday(&t2,0);

	double time2 = (t2.tv_sec - t1.tv_sec)*1000000 + (t2.tv_usec-t1.tv_usec);

	cout<<"time1 "<<time1<<endl
		<<"time2 "<<time2<<endl;

	return 0;

}

