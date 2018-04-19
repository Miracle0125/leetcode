#include<vector>
#include<iostream>
using namespace std;



/*
amazing solution!!
used1: check each row

used2: check each column

used3: check each sub-boxes

使用三个数组标记i行j列k框出现过的数字

*/
bool isValidSudoku(vector<vector<char>>& board) {
	int used1[9][9] = { 0 }, used2[9][9] = { 0 }, used3[9][9] = { 0 };
	for (unsigned  char i = 0; i < board.size(); i++)
	{
		for (unsigned char j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] != '.') {
				//计算数字在哪个框的算法非常好，i/x*x!=i
				int num = board[i][j] - '0' - 1,k = i/3*3+j/3;
				if (used1[i][num] || used2[j][num] || used3[k][num]) return false;
				used1[i][num] = used2[j][num] = used3[k][num] = 1;
			}
		}
	}
	return true;
}