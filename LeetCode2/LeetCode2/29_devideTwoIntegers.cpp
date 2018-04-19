#include<stdlib.h>
#include<iostream>
using namespace std;


//write it myself
int impl(int n,int a,int b) {
	if (a < b) return n;
	int c = b,n1 = n;
	while (a - (c=c <<1)>0)
		n1++;
	int d = n1 - n;
	if (d==0) return n+1;
	return impl(n+(1<<d), a-(b<<d), b);
}

int divide(int a, int b) {
	if (b == 0) return INT_MAX;
	bool neg = false;
	if (a == INT_MIN) { if (b == 1) return a; if (b == -1) return INT_MAX; if (b == 2 || b == -2) return a >> 1; if(b!=INT_MIN)a++; }
	if (b == INT_MIN) return a == INT_MIN ? 1: 0;
	if (a < 0) { a = -a; neg = !neg; }
	if (b < 0) { b = -b; neg = !neg; }
	return neg?-impl(0,a, b): impl(0, a, b);
}