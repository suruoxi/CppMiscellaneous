/*************************************************************************
    > File Name: moveSwap.cpp
    > Author: Peng Zhang
    > Mail: pengzhang_live@live.com 
    > Created Time: 2015-01-08
 ************************************************************************/

#include<iostream>
#include<ctime>
#include<sys/time.h>
#include<cstdlib>

using namespace std;

const int SIZE = 10000;
const int N    = 10000;

int A[SIZE];
int B[SIZE];


template<class T>
void swap1(T& a, T& b){
	T tmp(a); // copy a to tmp
	a = b;    // copy b to a 
	b = a;    // copy tmp to b
}

template<class T>
void swap2(T& a, T& b){
	T tmp(move(a));		// move a to tmp
	a = move(b);		// move b to a
	b = move(tmp);		// move tmp to b
}


int main(){
	srand(time(0));
	for(int i = 0; i != SIZE; ++i){
		A[i] = rand();
		B[i] = rand();
	}

	struct timeval t1, t2;

	gettimeofday(&t1,0);
	for(int i = 0; i != N; ++i)
		for(int j = 0; j != SIZE; ++j)
			swap1(A[j], B[j]);
	gettimeofday(&t2,0);

	cout<<"Time1 without move: "<< (t2.tv_sec - t1.tv_sec)*1000000 + (t2.tv_usec - t2.tv_usec) <<endl;

	gettimeofday(&t1,0);
	for(int i = 0; i != N; ++i)
		for(int j = 0; j != SIZE; ++j)
			swap2(A[j], B[j]);
	gettimeofday(&t2,0);

	cout<<"Time1 with move:    "<< (t2.tv_sec - t1.tv_sec)*1000000 + (t2.tv_usec - t2.tv_usec) <<endl;
	
	return 0;

}

