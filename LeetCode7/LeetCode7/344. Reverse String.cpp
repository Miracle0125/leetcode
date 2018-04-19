

#include"common.h"
using namespace std;


string reverseString(string s) {
	int n = s.size(), limit = n / 2;
	for (int i = 0; i < limit; i++)
		swap(s[i], s[n - 1 - i]);
	return s;
}


string reverseString2(string s) {
	int i = 0, j = s.size() - 1;
	while (i < j) {
		swap(s[i++], s[j--]);
	}

	return s;
}