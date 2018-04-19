
#include"common.h"
#include<vector>
#include<algorithm>

using namespace std;

//你说这人脑子怎么长得 ，想得出这种解答
vector<int> productExceptSelf(vector<int>& A) {
	vector<int> ret(A.size(),0);
	ret[0] = 1;
	for (int i = 1; i < A.size(); i++) {
		ret[i] = ret[i - 1] * A[i - 1];
	}
	int right = 1;
	for (int i = A.size() - 1; i >= 0; i--) {
		right *= A[i];
		ret[i] *= right;
	}
	return ret;
}

//me
vector<int> productExceptSelf2(vector<int>& A) {
	int product = 1, num_zeros = 0;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] == 0) {
			if (++num_zeros >= 2) return vector<int>(A.size(), 0);
			continue;
		}
		product *= A[i];
	}
	if (num_zeros) {
		for (int i = 0; i < A.size(); i++)
		{
			if (A[i] == 0) A[i] = product;
			else A[i] = 0;
		}
	}
	else for (int i = 0; i < A.size(); i++)
	{
		A[i] = product / A[i];
	}
	return A;
}