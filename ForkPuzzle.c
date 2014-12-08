/*************************************************************************
    > File Name: ForkPuzzle.c
    > Author: Peng Zhang
    > Mail: pengzhang_live@live.com 
    > Created Time: 2014-12-08
 ************************************************************************/
// http://coolshell.cn/articles/7965.html
// How many '-' will be printed ?
// 6 ?  No.  Actually it's 8
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	int i;
	for(i=0; i<2; i++){
		fork();
		printf("-");
	}
	wait(NULL);
	wait(NULL);

	return 0;
}

