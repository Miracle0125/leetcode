
#include<vector>
#include<algorithm>
using namespace std;


//取范围0- n-2,和1- n-1，第一个和最后一个为a和b，
//则有三种状态，选a，选b,和都不选
//1对应范围1，2对应范围2，3在1或2中
//所以取范围1和2的最大值即结果

int rob_in_range(vector<int>& A, int l, int r) {
	int n = r - l + 1;
	if (n == 0)return 0;
	if (n == 1) return A[l];
	int a = max(A[l], A[l + 1]), b = A[l], c;
	for (int i = 2; i < n; i++)
	{
		c = max(a, b + A[l + i]);
		b = a;
		a = c;
	}
	return a;
}

int rob(vector<int>& A) {
	int n = A.size(), a, b, c, ret = 0;
	if (n <= 3) {
		for (int i : A) 
			ret = max(ret, i);
		return ret;
	}
	for (int j = 0; j < 2; j++)
	{
		for (int i = 2+j, a = max(A[j], A[j+1]), b = A[j]; i-j<n; i++)
		{
			c = max(a, b + A[i]);
			b = a;
			a = c;
		}
		ret = max(ret, a);
	}
	return ret;
}

//int rob_in_range(vector<int>& A, int l, int r) {
//	int n = r - l + 1;
//	if (n == 0)return 0;
//	if (n == 1) return A[l];
//	int a = max(A[l], A[l + 1]), b = A[l], c;
//	for (int i = 2; i < n; i++)
//	{
//		c = max(a, b + A[l + i]);
//		b = a;
//		a = c;
//	}
//	return a;
//}
//
//int rob(vector<int>& A) {
//	int n = A.size();
//	if (n == 0)return 0;
//	if (n == 1) return A[0];
//	return max(rob_in_range(A, 0, A.size() - 2), rob_in_range(A, 1, A.size() - 1));
//}