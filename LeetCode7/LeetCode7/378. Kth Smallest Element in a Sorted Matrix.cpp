




using namespace std;
#include"common.h"


int kthSmallest(vector<vector<int>> matrix, int k) {
	int lo = matrix[0][0], hi = matrix[matrix.size() - 1][matrix[0].size() - 1] + 1;//[lo, hi)
	while (lo < hi) {
		int mid = lo + (hi - lo) / 2;
		int count = 0, j = matrix[0].size() - 1;
		for (int i = 0; i < matrix.size(); i++) {
			while (j >= 0 && matrix[i][j] > mid) j--;
			count += (j + 1);
		}
		if (count < k) lo = mid + 1;
		else hi = mid;
	}
	return lo;
}

//int main() {
//	vector<vector<int>> v{
//		{ 1,2,3,3,3 },
//		{ 3,3,3,3,3 },
//		{ 3,3,3,4,5 },
//		{ 5,5,5,5,5 }
//	};
//	kthSmallest(v, 4);
//	return 0;
//}