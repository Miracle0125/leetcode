
#include<string>
#include<iostream>
#include<vector>
using namespace std;


void rotate(vector<int>& A, int k) {
	int n = A.size();
	if (k >= n)k %= n;
	A.insert(A.begin(), A.begin() + (n-k), A.end());
	A.erase(A.begin() + n, A.end());
}