#include<string>
#include<iostream>

using namespace std;

typedef unsigned int uint32_t;

//看别人代码没看懂，看评论说是divide and conquer，瞬间明白了,遂自己写出代码如下........
uint32_t reverseBits(uint32_t n) {
	n = (n << 16) | (n >> 16);
	n = ((n << 8) & 0xff00ff00) | ((n >> 8) & 0x00ff00ff);
	n = ((n << 4) & 0xf0f0f0f0) | ((n >> 4) & 0x0f0f0f0f);
	n = ((n << 2) & 0xcccccccc) | ((n >> 2) & 0x33333333);
	n = ((n << 1) & 0xaaaaaaaa) | ((n >> 1) & 0x55555555);
	return n;
}