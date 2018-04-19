#include"common.h"
#include<vector>
using namespace std;


//最高解也是差不多一样繁琐
int m, n;
void go(int i ,int j, vector<vector<char>>& A){
	if (A[i][j]=='.' || A[i][j]=='X') return;
	A[i][j] = '.';
	if(i<m-1)
	go(i + 1, j, A);
	if(j>1)
	go(i, j - 1, A);
	if(i>1)
	go(i - 1, j, A);
	if(j<n-1)
	go(i, j + 1, A);
}

void solve(vector<vector<char>>& A) {
	if (A.empty()) return;
	m = A.size(),n = A[0].size();
	for (int i = 0; i < m; i++)
	{
		if (A[i][0] == 'O') go(i, 0,A);
		if (A[i][n-1] == 'O') go(i, n-1,A);
	}
	for (int i = 1; i < n-1; i++)
	{
		if (A[0][i] == 'O') go(0, i,A);
		if (A[m-1][i] == 'O') go(m-1, i,A);
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (A[i][j] != 'X') 
				if(A[i][j]=='O') A[i][j] = 'X';
				else A[i][j] = 'O';
}

//int main() {
//
//	vector<vector<char>>  v = fuck("OXXOX,XOOXO,XOXOX,OXOOO,XXOXO");
//	printMatrix(v);
//	solve(v);
//	printMatrix(v);
//	return 1;
//}