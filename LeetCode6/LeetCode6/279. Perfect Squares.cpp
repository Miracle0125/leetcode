


#include"common.h"
#include<algorithm>
using namespace std;


//造.....造化钟神秀 。 学不来学不来
int numSquares(int n)
{
	if (n <= 0) return 0;
	static vector<int> dp(n + 1), squre;
	for (int i = 1, _squre = 1; _squre <= n; _squre = ++i*i) squre.push_back(_squre);
	for (int m = 1; m <= n; m++)
	{
		int min_val = INT_MAX;
		for (int i = 0; i<squre.size() && squre[i] <= m; i++)
			min_val = min(min_val, dp[m - squre[i]] + 1);
		dp[m] = min_val;
	}
	return dp[n];
}


int main() {
auto ret=	numSquares(7);
	return 0;
}