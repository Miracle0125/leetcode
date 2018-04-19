






#include"common.h"
#include<unordered_map>


auto is_valid = [](int a, int b, int c) { return a + b > c; };
auto permutation = [](int m) {
	if (m <= 5) return m == 5 ? 20 : 4;
	return (m - 2)*(m - 1)*m;
};
int triangleNumber(vector<int>& A) {
	int r = 0, n = A.size();
	sort(A.begin(), A.end());
	for (int i = 0; i <= n - 3; i++)
	{
		if (A[i] != 0) {
			for (int j = i + 1; j <= n - 2; j++)
			{
				for (int k = j + 1; k < n; k++)
				{
					if (is_valid(A[i], A[j], A[k]))r++;
					else break;
				}
			}
		}
	}
	return r;
}


class Solution_611 {
public:
	int sum2Greater(const vector<int> &nums, int targetIdx) {
		int ret = 0;
		for (int i = 0, j = targetIdx - 1; i<j;) {
			if (nums[i] + nums[j] > nums[targetIdx]) {
				ret += j - i;
				j--;
			}
			else {
				i++;
			}
		}
		return ret;
	}

	int triangleNumber(vector<int>& nums) {
		int total = 0;
		sort(nums.begin(), nums.end());
		for (int i = nums.size() - 1; i >= 2; i--) {
			int validNum = sum2Greater(nums, i);
			total += validNum;
		}
		return total;
	}
};

