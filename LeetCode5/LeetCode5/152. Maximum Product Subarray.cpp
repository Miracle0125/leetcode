#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int maxProduct(vector<int>& A) {
	int n = A[0], P = n, N = n;
	for (int i = 1; i < A.size(); i++)
	{
		if (A[i] < 0)swap(P, N);
		P = max(A[i] * P, A[i]);
		N = min(A[i] * N, A[i]);
		n = max(P, n);
	}
	return n;
}


//int main() {
//	maxProduct(vector<int>{-4,-3});
//	return 1;
//}