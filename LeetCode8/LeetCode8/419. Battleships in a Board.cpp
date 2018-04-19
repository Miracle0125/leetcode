
#include"common.h"




int countBattleships(vector<vector<char>>& A) {
	if (A.size() == 0) return 0;
	int m = A.size(), n = A[0].size(), ret = 0;
	for (int i = 0; i < n; i++){
		if (A[0][i] == 'X') {
			ret++;
			while (i < n&&A[0][i] == 'X')i++;
		}
	}
	for (int  i = 1; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (A[i][j] == 'X'&&A[i - 1][j] != 'X') {
				ret++;
				while (j < n&&A[i][j] == 'X')j++;
			}
		}
	}
	return ret;
}