#include<vector>
//#include<iostream>
using namespace std;


/*
* clockwise rotate
* first reverse up to down, then swap the symmetry
* 1 2 3     7 8 9     7 4 1
* 4 5 6  => 4 5 6  => 8 5 2
* 7 8 9     1 2 3     9 6 3
*/

void rotate(vector<vector<int>>& mat) {
	int n = mat.size();
	for (int i = 0; i <=(n-1)/2; i++)
		swap(mat[i], mat[n - 1 - i]);
	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++)
			swap(mat[i][j],mat[j][i]);
}