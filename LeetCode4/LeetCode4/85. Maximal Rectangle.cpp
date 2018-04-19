#include<vector>
#include<algorithm>
#include<stack>
#include<iostream>
using namespace std;

void printMatrix(vector<vector<int>> &v) {
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			cout << v[i][j] /*<< ""*/;
			//if (!(v[i][j] / 10)) cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}

//自己根据84改写的,map 可以改成一维
int maximalRectangle(vector<vector<char>>& A) {
		if(A.empty()) return 0;
		int m = A.size(),n = A[0].size(),j,ret=0;
		vector<vector<int>> h(m+1,vector<int>(n+2,0));
		stack<int> s;
		for (int i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
				h[i + 1][j + 1] = A[i][j] == '1' ? h[i][j + 1] + 1 : 0;
			for (j = 0; j < n+1; j++)
			{
				while (s.size() > 0 && h[i + 1][j + 1] <= h[i+1][s.top()]) {
					int height = h[i+1][s.top()];
					s.pop();
					ret = max(ret, height*(j - (s.size() > 0 ? s.top() : 0)));
				}
				s.push(j + 1);
			}
			while (!s.empty())
				s.pop();
		}
		return ret;
}

//
//int main() {
//	int ret = maximalRectangle(vector<vector<char>> { 
//		{1,0,1,0,0},
//		{1,0,1,1,1}, 
//		{1,1,1,1,1},
//		{1,0,0,1,0}
//	});
//	return ret;
//}


//还没看

//dp       
//int maximalRectangle2(vector<vector<char> > &matrix) {
//	if (matrix.empty()) return 0;
//	const int m = matrix.size();
//	const int n = matrix[0].size();
//	int left[n], right[n], height[n];
//	fill_n(left, n, 0); fill_n(right, n, n); fill_n(height, n, 0);
//	int maxA = 0;
//	for (int i = 0; i<m; i++) {
//		int cur_left = 0, cur_right = n;
//		for (int j = 0; j<n; j++) { // compute height (can do this from either side)
//			if (matrix[i][j] == '1') height[j]++;
//			else height[j] = 0;
//		}
//		for (int j = 0; j<n; j++) { // compute left (from left to right)
//			if (matrix[i][j] == '1') left[j] = max(left[j], cur_left);
//			else { left[j] = 0; cur_left = j + 1; }
//		}
//		// compute right (from right to left)
//		for (int j = n - 1; j >= 0; j--) {
//			if (matrix[i][j] == '1') right[j] = min(right[j], cur_right);
//			else { right[j] = n; cur_right = j; }
//		}
//		// compute the area of rectangle (can do this from either side)
//		for (int j = 0; j<n; j++)
//			maxA = max(maxA, (right[j] - left[j])*height[j]);
//	}
//	return maxA;
//}