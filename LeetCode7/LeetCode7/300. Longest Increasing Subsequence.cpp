


using namespace std;
#include"common.h"
#include<stack>
#include<algorithm>
#include<list>





//int smaller_nums(vector<int>& A,int num) {
//	printMatrix(A); cout << num << endl;
//	//if (A.back() < num) return A.size();
//	//if (A[0] >= num) return 0;
//	int l = 0, r = A.size()-1;
//	while (r - l ) {
//		int mid = (l + r) / 2;
//		if (A[mid] >= num)r = mid;
//		else if (A[mid] < num)l = mid+1;
//	}
//	cout << l << endl;
//	return l;
//}
//
//int lengthOfLIS(vector<int>& A) {
//	int i = 1, n = A.size(), len = min(1,n),small;
//	vector<int> s,t;
//	for (; i < n; i++)
//		if (A[i] > A[i - 1]) {
//			s.push_back(A[i - 1]), s.push_back(A[i]), len = 2;
//			break;
//		}
//	for (i++; i < n; i++) {
//		if (A[i] > s.back()) {
//			s.push_back(A[i]), len = max(len, (int)s.size()), t ={};
//		}
//		else { 
//			if (t.empty()||A[i] > t.back()) t.push_back(A[i]);
//			else {
//				while (!t.empty() && t.back() >= A[i])
//					t.erase(t.end()-1);
//				t.push_back(A[i]);
//			} 
//			small = smaller_nums(s, t[0]);
//			if (small >= t.size()-s.size()) {
//				s.erase(s.begin() + small, s.end());
//				s.insert(s.end(), t.begin(), t.end());
//				len = max(len, (int)s.size());
//				t.clear();
//			}
//		}
//	}
//	return len;
//}


static int binarySearch(vector<int> &a, int fromIndex, int toIndex,
	int key) {
	int low = fromIndex;
	int high = toIndex - 1;

	while (low <= high) {
		int mid = (low + high) >> 1;
		int midVal = a[mid];

		if (midVal < key)
			low = mid + 1;
		else if (midVal > key)
			high = mid - 1;
		else
			return mid; // key found
	}
	return -(low + 1);  // key not found.
}

int lengthOfLIS(vector<int> nums) {
	vector<int> dp(nums.size());
	int len = 0;

	for (int x : nums) {
		int i = binarySearch(dp, 0, len, x);
		if (i < 0) i = -(i + 1);
		dp[i] = x;
		if (i == len) len++;
	}

	return len;
}

//for (i++; i < n; i++) {
//	if (A[i] > s.top()) s.push(A[i]), len = max(len, (int)s.size());
//	else {
//		while (!s.empty() && s.top() >= A[i])
//			s.pop();
//		s.push(A[i]);
//	}
//}