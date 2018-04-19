
using namespace std;
#include"common.h"
#include<algorithm>


//O(n) space
void wiggleSort(vector<int>& A) {
	int n = A.size(), i = (n - 1) / 2, j = n - 1;
	sort(A.begin(), A.end());
	vector<int>ret(n);
	for (int k = 0; k < n; k++) {
		ret[k] = (k & 1) ? A[j--] : A[i--];
	}
	A = ret;
}


//O(1) space ,±È½ÏÐþÃî
void wiggleSort2(vector<int>& nums) {
	int n = nums.size();

	// Find a median.
	auto midptr = nums.begin() + n / 2;
	nth_element(nums.begin(), midptr, nums.end());
	int mid = *midptr;

	// Index-rewiring.
#define A(i) nums[(1+2*(i)) % (n|1)]

	// 3-way-partition-to-wiggly in O(n) time with O(1) space.
	int i = 0, j = 0, k = n - 1;
	while (j <= k) {
		if (A(j) > mid)
			swap(A(i++), A(j++));
		else if (A(j) < mid)
			swap(A(j), A(k--));
		else
			j++;
	}
}