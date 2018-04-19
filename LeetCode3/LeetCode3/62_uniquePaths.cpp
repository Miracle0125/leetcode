#include<vector>
using namespace std;

int uniquePaths(int m, int n) {
	vector<vector<int>> map(m, vector<int>(n, 1));
	for (int i = 1; i < m; i++)
		for (int j = 1; j < n; j++)
			map[i][j] = map[i - 1][j] + map[i][j-1];
	return map[m - 1][n - 1];
}



bool isValid(int x,int y) {
	return x >= 0 && y >= 0;
}
//自己想的差解
int uniquePaths2(int m, int n) {
	vector<vector<int>> map(m,vector<int>(n,0));
	map[0][0] = 1;
	int dx=-1, dy=0, x = 0, y = 0;
	while (x != m - 1 && y != n - 1) {
		if (isValid(x,y)) {
			//x = x - 1, y = y + 1;
			if (isValid(x-1,y))map[x][y]+=map[x-1][y];
			if (isValid(x, y-1))map[x][y] += map[x][y-1];
			x--; y++;
		}else{
			
			swap(x, y);
			y--;
			y += x + 1;
			//y = y > n - 1 ? n - 1 : y;
			if (y > n - 1) { y = n - 1; x = y - n + 1; }
		}
		//dx = x - 1; dy = y + 1;
	}
	return map[m - 1][n - 1];
}

//int main() {
//	uniquePaths(3,3);
//}