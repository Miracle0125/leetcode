


#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int rob(vector<int>& A) {
	int n = A.size();
	if (n == 0)return 0;
	if (n == 1) return A[0];
	vector<int> f(n);
	f[0] = A[0];
	f[1] = max(A[0], A[1]);
	for (int i = 2; i < n; i++)
	{
		f[i] = max(f[i - 1], f[i - 2] + A[i]);
	}
	return f[n - 1];
}

//O(1) space
//a 前一个，b 前两个，c目前的
int rob_ver2(vector<int>& A) {
	int n = A.size();
	if (n == 0)return 0;
	if (n == 1) return A[0];
	int a = max(A[0], A[1]),b = A[0],c;
	for (int i = 2; i < n; i++)
	{
		c = max(a, b + A[i]);
		b = a;
		a = c;
	}
	return a;
}