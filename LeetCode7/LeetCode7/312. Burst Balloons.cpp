


#include<vector>
using namespace std;
#include<algorithm>




//教科书式的代码。。。。
//

int burst(vector<vector<int>> memo, vector<int> nums, int left, int right) {
	if (left + 1 == right) return 0;
	if (memo[left][right] > 0) return memo[left][right];
	int ans = 0;
	for (int i = left + 1; i < right; ++i)
		ans = max(ans, nums[left] * nums[i] * nums[right]
			+ burst(memo, nums, left, i) + burst(memo, nums, i, right));
	memo[left][right] = ans;
	return ans;
}
int maxCoins(vector<int> iNums) {
	vector<int> nums(iNums.size() + 2);
	int n = 1;
	for (int x : iNums) if (x > 0) nums[n++] = x;
	nums[0] = nums[n++] = 1;


	vector<vector<int>> memo(n, vector<int>(n));
	return burst(memo, nums, 0, n - 1);
}




int maxCoinsDP(vector<int> &iNums) {
	vector<int> nums(iNums.size() + 2);
	int n = 1;
	for (int x : iNums) if (x > 0) nums[n++] = x;
	nums[0] = nums[n++] = 1;


	vector<vector<int>> dp(n, vector<int>(n));
	for (int k = 2; k < n; ++k) {
		for (int left = 0; left < n - k; ++left) {
			int right = left + k;
			for (int i = left + 1; i < right; ++i)
				dp[left][right] = max(dp[left][right],
					nums[left] * nums[i] * nums[right] + dp[left][i] + dp[i][right]);
		}
	}

	return dp[0][n - 1];
}