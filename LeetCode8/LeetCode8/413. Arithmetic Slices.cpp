

#include"common.h"


int numberOfArithmeticSlices(vector<int>& A) {
	if (A.size() < 3) return 0;
	int ret = 0, cur_sum = 0, n = A.size(), prev = A[1] - A[0];
	for (int i = 2; i < n; i++)
	{
		int cur = A[i] - A[i - 1];
		if (cur == prev) {
			cur_sum += 1;
			ret += cur_sum;
		}
		else cur_sum = 0;
		prev = cur;
	}
	return ret;
}