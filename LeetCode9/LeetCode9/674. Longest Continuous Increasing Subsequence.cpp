

#include"common.h"

int findLengthOfLCIS(vector<int>& A) {
	int n = A.size(), r = 1, len = 1;
	if (!n) return 0;
	for (int i = 1; i < n; i++)
	{
		if (A[i] > A[i - 1])len++;
		else {
			r = max(r, len);
			len = 1;
		}
	}
	return max(r,len);
}