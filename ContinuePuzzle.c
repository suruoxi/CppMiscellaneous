/*************************************************************************
    > File Name: ContinuePuzzle.c
    > Author: Peng Zhang
    > Mail: pengzhang_live@live.com 
    > Created Time: 2014-12-08
 ************************************************************************/
/*
 * 这段代码的本意是：如果 i 在 0 ～14之间， 那么通过continue来绕过之后的语句，从而继续
 * 循环。 当i到达15， 判断条件为false，就会退出，这样希望能够输出 0 ～ 14.
 * 但continue的含义是： 不执行循环体内之后的部分，直接到循环点。而 while(false)不属于循环体，而是
 * 循环点，所以该代码只会输出1
 */
#include<stdio.h>

enum {
	false,
	true
};

int main(){
	int i = 1;
	do{
		printf("%d\n",i++);
		if(i < 15)
			continue;
	}while(false);

	return 0;
}
