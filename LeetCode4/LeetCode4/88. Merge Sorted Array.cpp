#include<vector>
#include<algorithm>
using namespace std;


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int i = 0, j = 0;
	while (i < m&&j < n)
		if (nums1[i] >= nums2[j])
			nums1.push_back(nums2[j++]);
		else
			nums1.push_back(nums1[i++]);
	for (; i<m; i++) nums1.push_back(nums1[i]);
	for (; j<n; j++) nums1.push_back(nums2[j]);
	nums1.erase(nums1.begin(), nums1.begin() + m);
}


void merge2(vector<int>& A, int m, vector<int>& B, int n) {
	int i = m - 1;
	int j = n - 1;
	int k = m + n - 1;
	while (i >= 0 && j >= 0)
	{
		if (A[i] > B[j])
			A[k--] = A[i--];
		else
			A[k--] = B[j--];
	}
	while (j >= 0)
		A[k--] = B[j--];
}


//int main() {
//	vector<int> nums1 = vector<int>{ 1, 2, 3, 4, 5 };
//	merge(nums1, 5, vector<int>{},0);
//	return 1;
//}