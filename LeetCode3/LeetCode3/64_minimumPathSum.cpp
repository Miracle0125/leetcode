#include<vector>
#include<iostream>
#include<algorithm>
#include"common.h"
using namespace std;

void printMatrix(vector<vector<int>> &v) {
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[0].size(); j++)
		{
			cout << v[i][j] << " ";
			if (!(v[i][j] / 10)) cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}

//I love DP  ! write it myself
//空间复杂度换时间复杂度
int minPathSum(vector<vector<int>>& A) {
	int m = A.size(), n = A[0].size(),i;
	vector<vector<int>> map(m+1, vector<int>(n+1, 0));
	for (i = 0; i < n; i++)
		map[1][i + 1] = A[0][i] + map[1][i];
	for (i = 1; i < m; i++)
		map[i+1][1] = A[i][0] + map[i][1];
	for (i = 1; i < m; i++)
		for (int j = 1; j < n; j++)
			map[i+1][j+1] = A[i][j] + min(map[i][j + 1],map[i + 1][j]);
	printMatrix(map);
	return map[m][n];
}

//int main() {
//	minPathSum(vector<vector<int>>{
//		//{1,4,7},
//		//{5,2,3},
//		//{6,9,4}
//		//{1,2,5}, {3,2,1}
//		/*{1,2} ,{1,1}*/
//		{1}
//	});
//}