

using namespace std;
#include"common.h"
#include<algorithm>


//能保证输出的INDEx顺序是正确的（...）
bool increasingTriplet(vector<int>& A) {
	int a=INT_MAX, b = INT_MAX, i = 1, n = A.size();
	for (; i < n; i++)
		if (A[i] > A[i - 1]) {
			a = A[i - 1], b = A[i];
			break;
		}
	for (i++; i < n-1; i++) {
		if (A[i] > b) return true;
		else if (A[i] > a) b = A[i];
		else if (A[i + 1] > A[i]) { 
			if (A[i + 1] > b) return true;
			a = A[i], b = A[i++ + 1]; 
		}
	}
	return n&& A[n - 1] > b;
}


//clean
bool increasingTriplet2(vector<int>& nums) {
	int c1 = INT_MAX, c2 = INT_MAX;
	for (int x : nums) {
		if (x <= c1) {
			c1 = x;           // c1 is min seen so far (it's a candidate for 1st element)
		}
		else if (x <= c2) { // here when x > c1, i.e. x might be either c2 or c3
			c2 = x;           // x is better than the current c2, store it
		}
		else {              // here when we have/had c1 < c2 already and x > c2
			return true;      // the increasing subsequence of 3 elements exists
		}
	}
	return false;
}