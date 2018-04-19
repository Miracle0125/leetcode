
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int minSubArrayLen(int s, vector<int>& A) {
	int min_len = INT_MAX, len = 1;
	for (int i = 0,sum=0; i < A.size(); i++,len++)
	{
		sum += A[i];
		if (sum >= s) {
			while (sum - A[i - (len - 1)] >= s) 
				sum -= A[i - (len-- - 1)];
			min_len = min(min_len,len);
		} 
	}
	if (min_len != INT_MAX || min_len == INT_MAX&&len == INT_MAX+1) 
		return min_len;
	else return 0;
}