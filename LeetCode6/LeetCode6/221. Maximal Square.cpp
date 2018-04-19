#include"common.h"
#include<vector>
#include<algorithm>

using namespace std;
int maximalSquare(vector<vector<char>>& A) {
	int len = 0, l = 0;
	if (A.size()) {
		vector<int>f = vector<int>(A[0].size(),0);
		for (int i = 0; i < A.size(); i++)
		{
			for (int j = 0; j < A[0].size(); j++)
			{
				if (A[i][j]=='0') f[j] = 0;
				else {
					 l = ++f[j];
					 for (int k = 1; k < f[j], j - k >= 0, f[j - k]>1; k++) {
						l = min(f[j - k], l);
						len = max(len, min(k + 1, l));
					}
				}
			}
		}
		if (!len)return l ? 1 : 0;
	}
	return len*len;
}