/*************************************************************************
    > File Name: ArrayBT.c
    > Author: Peng Zhang
    > Mail: pengzhang_live@live.com 
    > Created Time: 2014-12-09
 ************************************************************************/

/*
 *  c中，属于数组 a 和整型 i，a[i] 和 i[a] 是等价的。 无语
 */ 


#include<stdio.h>

int main(){
	int a = 3, b = 5;
	printf(&a["Ya!Hello! How is this? %s\n"], &b["junk/super"]);
	printf(&a["WHAT%c%c%c  %c%c  %c !\n"], 1["this"],2["beauty"],0["tool"],0["is"],3["sensitive"],4["CCCCCC"]);

	return 0;
}
