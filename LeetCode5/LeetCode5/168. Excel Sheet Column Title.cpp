
#include<string>
#include<iostream>
#include<vector>
using namespace std;


string convertToTitle(int n) {
	return n==0 ? "" : convertToTitle((n-1) / 26)+char(((n % 26) == 0 ? 26 : n % 26)+64);
}