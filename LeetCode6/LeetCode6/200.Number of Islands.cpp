#include<vector>
#include"common.h"
using namespace std;
#define max( c1, c2) c1>c2?c1:c2;
void printMatrix(vector<vector<char>> &v) {
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
//vector<vector<bool>> f;
vector<vector<char>> A;
void DFS_impl(int i,int j) {
	if (A[i][j] == '0') return;
	A[i][j] = '0';
	DFS_impl(i + 1, j);
	DFS_impl(i - 1, j);
	DFS_impl(i, j + 1);
	DFS_impl(i, j - 1);
}

int numIslands(vector<vector<char>> src) {
	A = src;
	if (A.size() == 0) return 0;

	A.insert(A.begin(), vector<char>(A[0].size(),'0'));
	A.push_back(vector<char>(A[0].size(), '0'));
	for (int i = 0; i < A.size(); i++)
	{
		A[i].insert(A[i].begin(), '0');
		A[i].push_back('0');
	}
	printMatrix(A);
	int m = A.size(), n = A[0].size(),ret=0;
	//f = vector<vector<bool>> (m, vector<bool>(n));
	for (int i = 1; i < m-1; i++)
	{
		for (int j = 1; j < n-1; j++)
		{
			if (A[i][j] == '1') {
				ret++;
				DFS_impl(i, j);
				printMatrix(A);
			}
		}
	}
	return ret;
}


//int main() {
//
//	vector<vector<string>> v = { { "1","1","1","1","0" },{ "1","1","0","1","0" },{ "1","1","0","0","0" },{ "0","0","0","0","0" } };
//	vector<vector<char>> src(v.size(), vector<char>(v[0].size()));
//	for (int i = 0; i < v.size(); i++)
//	{
//		for (int j = 0; j < v[i].size(); j++)
//		{
//			src[i][j] = v[i][j][0];
//		}
//	}
//	numIslands(src);
//	printMatrix_str(v);
//	//printMatrix(v);
//
//
//	return 0;
//}


//int numIslands(vector<vector<char>> A) {
//	if (A.size() == 0) return 0;
//	int m = A.size(), n = A[0].size();
//	vector<vector<int>> f(m+1, vector<int>(n+1, 0));
//	vector<char> v(n, 0);
//	A.insert(A.begin(), v);
//	for (int i = 0; i < A.size(); i++)
//	{
//		A[i].insert(A[i].begin(), 0);
//	}
//	for (int i = 1; i <= m; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			if (A[i][j] == '0') {
//				f[i][j] = max(f[i][j-1],f[i-1][j]);
//			}else{
//				if (A[i-1][j] == '1') {
//					if (A[i][j-1] == '1')
//						f[i][j-1] = f[i-1][j];
//					f[i][j]= f[i-1][j];
//				}
//				else {
//					if(A[i][j-1]== '1')
//						f[i][j] = f[i][j - 1];
//					else {
//						char c = max(f[i][j - 1], f[i - 1][j]);
//						for (int k = 0, num = atoi(&c) + 1; k <= j; k++)
//							f[i][j] = num;
//					}
//				}
//			}
//		}
//		printMatrix(f);
//		cout << endl;
//	}
//	
//	
//	return f[m][n];
//}

