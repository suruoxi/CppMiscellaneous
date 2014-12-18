/*************************************************************************
    > File Name: RealRandom.c
    > Author: Peng Zhang
    > Mail: pengzhang_live@live.com 
    > Created Time: 2014-12-18
 ************************************************************************/

/* From    http://www.360doc.com/content/12/0410/17/532901_202526368.shtml
 * /dev/random把系统硬件噪声存储起来，需要的时候用来产生随机整数。但是如果读取时，池内没有足够的数据，就会阻塞等待。
 * /dev/urandom 不会阻塞，但不保证返回的是合适的数据，所以要多读几次？？
 * 详情参考 zim wiki
 */ 
#include<stdio.h>
#include<sys/time.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

unsigned int rand1(){
	int fd;
	unsigned int n = 0;
	fd = open("/dev/random", O_RDONLY);
	if( fd > 0){
		read(fd, &n, sizeof(n));
		close(fd);
	}
	return n;
}
// use /dev/urandom
void init_random(){
	unsigned int ticks;
	struct timeval tv;
	int fd;
	gettimeofday(&tv, NULL);
	ticks = tv.tv_sec + tv.tv_usec;
	fd = open("/dev/urandom",O_RDONLY);
	if( fd > 0){
		unsigned int r;
		int i;
		for( i = 0; i < 512; i++){
			read(fd, &r, sizeof(r));
			ticks += r;
		}
		close(fd);
	}
	srand(ticks);
}

int main(){
	int n;
	// test the /dev/random method
	srand(rand1());
	n = rand();
	printf("n = %d\n",n);

	// test the /dev/urandom method
	init_random();
	n = rand();
	printf("n = %d\n",n);

	return 0;
}
