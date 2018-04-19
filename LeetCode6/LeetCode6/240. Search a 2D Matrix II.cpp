

#include"common.h"
#include<vector>
#include<algorithm>

using namespace std;

//原来想得太复杂了
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int m = matrix.size();
	if (m == 0) return false;
	int n = matrix[0].size();

	int i = 0, j = n - 1;
	while (i < m && j >= 0) {
		if (matrix[i][j] == target)
			return true;
		else if (matrix[i][j] > target) {
			j--;
		}
		else
			i++;
	}
	return false;
}

//#define op(a,b) (pair<int,int>((a.first+b.first)/2,(a.second+b.second)/2))
//
//
//bool binary_search(vector<vector<int>>& A,) {
//
//}
//
//bool searchMatrix(vector<vector<int>>& A, int t) {
//	int ret = false;
//	if (A.size()) {
//		int m = A.size(), n = A[0].size();
//		if (m == 1) {
//			for (int i = 0; i < A[0].size(); i++)
//				if (A[0][i] == t) return true;
//		}else{
//			pair<int,int> a(0,0),b(m-1,n-1),mid;
//			while (b.first - a.first > 1 && b.second - a.second > 1) {
//				mid = op(a, b);
//				if (A[mid.first][mid.second] > t)
//					b = mid;
//				else if (A[mid.first][mid.second] < t)
//					a = mid;
//				else return true;
//			}
//		}
//	}
//	return ret;
//}

//int x0 = 0, y0 = 0, x1 = m - 1, y1 = n - 1;