/*************************************************************************
    > File Name: wordWrapCharWrap.cpp
    > Author: Peng Zhang
    > Mail: pengzhang_live@live.com 
    > Created Time: 2015-01-05
 ************************************************************************/

#include<iostream>
#include<sys/time.h>

int main(){
	struct timeval t1, t2;

	gettimeofday(&t1,0);
	for(int i=0; i != 1000; ++i)
		for(int j=0; j != 1000; ++j)
			std::cout<<"B";
	gettimeofday(&t2,0);
	double time1 = (t2.tv_sec - t1.tv_sec) + (t2.tv_usec - t1.tv_usec)/1000000.0;


	gettimeofday(&t1,0);
	for(int i=0; i != 1000; ++i)
		for(int j=0; j != 1000; ++j)
			std::cout<<"#";
	gettimeofday(&t2,0);
	double time2 = (t2.tv_sec - t1.tv_sec) + (t2.tv_usec - t1.tv_usec)/1000000.0;

	std::cout<<std::endl
			 <<std::endl
			 <<"time1: "<<time1<<std::endl
			 <<"time2: "<<time2<<std::endl;

	return 0;
}


