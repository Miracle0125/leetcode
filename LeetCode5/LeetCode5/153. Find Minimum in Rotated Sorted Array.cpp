

#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class _153 {
public:
	int findMin(vector<int>& A) {
		int len = A.size(), l = 0, r = len - 1;
		if (A[0] <= A[r]) return A[0];
		if (len == 2) return min(A[0], A[1]);
		while (l <= r) {
			int mid = (l + r) / 2;
			if (A[mid] > A[0])
				l = mid + 1;
			else if (A[mid - 1] < A[mid])
				r = mid;
			else return A[mid];
		}
	}
};


