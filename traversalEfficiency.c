/*************************************************************************
    > File Name: traversalEfficiency.c
    > Author: Peng Zhang
    > Mail: pengzhang_live@live.com 
    > Created Time: 2014-12-26
 ************************************************************************/

#include<stdio.h>
#include<sys/time.h>

#define SIZE 10000

int mat[SIZE][SIZE];

int main(){
	struct timeval s, e;
	gettimeofday(&s, 0);
	int i=0, j=0;
	for(i=0; i != SIZE; i++){
		for(j=0; j != SIZE; j++)
			mat[i][j] = (i+j) % 7;
	}
	gettimeofday(&e, 0);
	double time1 = 1000000*(e.tv_sec - s.tv_sec) + e.tv_usec - s.tv_usec;
	printf("%f ms\n",time1/1000);

	gettimeofday(&s, 0);
	for(i=0; i != SIZE; i++){
		for(j=0; j != SIZE; j++)
			mat[j][i] = (i+j) % 7;
	}
	gettimeofday(&e, 0);
	double time2 = 1000000*(e.tv_sec - s.tv_sec) + e.tv_usec - s.tv_usec;
	printf("%f ms\n",time2/1000);

	return 0;
}
