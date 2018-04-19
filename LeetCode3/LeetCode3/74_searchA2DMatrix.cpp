
#include<algorithm>
#include<vector>
using namespace std;



//把它当做一个整体
bool searchMatrix2(vector<vector<int> > &A, int t) {
	if (A.size() == 0 || A[0].size() == 0) return false;
	int m = A.size(), n = A[0].size(), l = 0, r = m*n - 1, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if(A[mid/n][mid%n]>t) { r = mid - 1; }
		else if (A[mid / n][mid%n] <t) { l = mid + 1; }
		else return true;
	}
	return false;
}




bool searchMatrix(vector<vector<int> > &A, int t) {
	if (A.size() == 0 || A[0].size()==0) return false;
	int m = A.size(),n = A[0].size(), l = 0, r = m - 1, mid, tc;
	while (l <= r) {
		mid = (l + r) / 2;
		if (A[mid][0] > t) { r = mid - 1; }
		else if (A[mid][n - 1] < t) { l = mid + 1; }
		else break;
	}
	if (mid == -1 || mid == m) return false;
	l = 0, r = n - 1,tc=mid,mid=(l+r)/2;
	while (l <= r) {
		mid = (l + r) / 2;
		if (A[tc][mid] > t) { r = mid - 1; }
		else if (A[tc][mid] < t) { l = mid + 1; }
		else return true;
	}
	return false;
}