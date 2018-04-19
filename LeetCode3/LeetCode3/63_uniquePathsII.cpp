#include<vector>
#include"common.h"
using namespace std;

//╦двт62
int uniquePathsWithObstacles(vector<vector<int>> A) {
	int m = A.size(), n = A[0].size();
	vector<vector<int>> map(m+1, vector<int>(n+1, 0));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			map[i + 1][j + 1] = A[i][j] == 1 ? 0 : 1;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			if (i == 0 && j == 0) continue;
			if (map[i + 1][j + 1] == 0) continue;
			map[i + 1][j + 1] = map[i][j + 1] + map[i + 1][j];
		}
	return map[m][n];
}


//int main() {
//	uniquePathsWithObstacles(vector<vector<int>>{
//
//		{0,0,0}, {0,1,0}, {0,0,0}
//	});
//}