#include"common.h"
#include<vector>
using namespace std;

void setZeroes2(vector<vector<int> > &A) {
	int col0 = 0,row0=0, m = A.size(), n = A[0].size();
	for (int i = 0; i < m; i++)
		if (!A[i][0]) {
			col0 = 1;
			break;
		}
	for (int i = 0; i < n; i++)
		if (!A[0][i]) {
			row0 = 1;
			break;
		}
	for (int i = 1; i < m; i++)
		for (int j = 1; j < n; j++)
			if (!A[i][j]) 
				A[i][0] = A[0][j] = 0;
	for (int i = 1; i < m; i++)
		if (!A[i][0]) 
			for (int j = 0; j < n; j++)
				A[i][j] = 0;
	for (int i = 1; i < n; i++)
		if(!A[0][i])
			for (int j = 0; j < m; j++)
				A[j][i] = 0;
	if(col0)
		for (int i = 0; i < m; i++)
			A[i][0] = 0;
	if(row0)
		for (int i = 0; i < n; i++)
			A[0][i] = 0;
}


//设ij为0，则在i,0   0,j标记之
//shorter,  but not that easy to read
void setZeroes(vector<vector<int> > &matrix) {
	int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
	for (int i = 0; i < rows; i++) {
		if (matrix[i][0] == 0) col0 = 0;
		for (int j = 1; j < cols; j++)
			if (matrix[i][j] == 0)
				matrix[i][0] = matrix[0][j] = 0;
	}

	for (int i = rows - 1; i >= 0; i--) {
		for (int j = cols - 1; j >= 1; j--)
			if (matrix[i][0] == 0 || matrix[0][j] == 0)
				matrix[i][j] = 0;
		if (col0 == 0) matrix[i][0] = 0;
	}

	printMatrix(matrix);
}