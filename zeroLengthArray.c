/*************************************************************************
    > File Name: zeroLengthArray.c
    > Author: Peng Zhang
    > Mail: pengzhang_live@live.com 
    > Created Time: 2014-12-22
 ************************************************************************/

/*
 * https://gcc.gnu.org/onlinedocs/gcc-4.1.1/gcc/Zero-Length.html#Zero-Length
 * http://www.cnblogs.com/hazir/p/variable_length_array.html
 */

/*
 * 适合固定头部的可变对象
 */ 
struct line{
	int length;
	char contents[0];
};

struct line *thisline = (struct line *)malloc(sizeof(struct line) + this_length);

thisline->length = this_length;


/*  其他用法 */
struct f1{
	int x;
	int y[];
} f={1,{2,3,4}};

/* 上述定义等价于下面的 */

struct f2{
	struct f1 f;
	int data[3];
} f = { {1},{2,3,4}};

/* 限制 */
struct foo { int x; int y[]; };
struct bar { struct foo z; };
     
struct foo a = { 1, { 2, 3, 4 } };        // Valid.
struct bar b = { { 1, { 2, 3, 4 } } };    // Invalid.
struct bar c = { { 1, { } } };            // Valid.
struct foo d[1] = { { 1 { 2, 3, 4 } } };  // Invalid.