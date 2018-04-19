#include<string>
#include<iostream>
#include<vector>
using namespace std;


//vector<int> twoSum(vector<int>& A, int T) {
//	for (int i = 0; i < A.size()-1; i++)
//	{
//		if (A[i] + A[A.size() - 1] < T) continue;
//		for (int j = i+1; j < A.size(); j++)
//		{
//			if (A[i] + A[j] == T) return vector<int>{i + 1, j + 1};
//			else if (A[i] + A[j] > T) break;
//		}
//	}
//}


vector<int> twoSum(vector<int>& A, int T) {
	int l = 0, r = A.size() - 1;
	while (l < r) {
		if (A[l] + A[r] > T)
			r--;
		else if (A[l] + A[r] < T)
			l++;
		else return vector<int>{l+1, r + 1};
	}
}