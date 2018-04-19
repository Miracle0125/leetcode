

#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& A) {
	int M = A[0], count = 1;
	for (int i = 1; i < A.size(); i++)
	{
		if (count == 0) {
			M = A[i];
			count++;
		}
		else if (A[i] == M)count++;
		else count--;
	}
	return M;
}