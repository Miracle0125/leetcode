#include<string>
#include<iostream>
#include<vector>
using namespace std;


int titleToNumber(string s) {
	int ret = 0;
	for (int i = s.size() - 1, m = 1; i >= 0; i--, m *= 26)
		ret += ((int)s[i] - 'A' + 1)*m;
	return ret;
}