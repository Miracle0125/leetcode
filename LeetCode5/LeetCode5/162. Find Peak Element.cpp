
#include<string>
#include<iostream>
#include<vector>
using namespace std;

int findPeakElement(vector<int>& A) {
	int val = INT_MIN, ret = 0;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] > val) { ret = i; val = A[i]; }

	}
	return ret;
}