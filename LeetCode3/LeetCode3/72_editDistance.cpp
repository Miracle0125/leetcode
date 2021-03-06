#include<algorithm>
#include<vector>
using namespace std;

//classic dp!!!   教科书式的答案
int minDistance(string word1, string word2) {
	int m = word1.length(), n = word2.length();
	vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= m; i++)
		dp[i][0] = i;
	for (int j = 1; j <= n; j++)
		dp[0][j] = j;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (word1[i - 1] == word2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			//分别对应插入  删除  替换
			else dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));
		}
	}
	return dp[m][n];
}

//蜜汁简化版本,魔法一般的代码，看不懂
int minDistance2(string word1, string word2) {
	int m = word1.length(), n = word2.length();
	vector<int> cur(m + 1, 0);
	for (int i = 1; i <= m; i++)
		cur[i] = i;
	for (int j = 1; j <= n; j++) {
		int pre = cur[0];
		cur[0] = j;
		for (int i = 1; i <= m; i++) {
			int temp = cur[i];
			if (word1[i - 1] == word2[j - 1])
				cur[i] = pre;
			else cur[i] = min(pre + 1, min(cur[i] + 1, cur[i - 1] + 1));
			pre = temp;
		}
	}
	return cur[m];
}