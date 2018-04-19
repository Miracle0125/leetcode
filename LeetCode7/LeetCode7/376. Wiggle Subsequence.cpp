


using namespace std;
#include"common.h"



//写不出这么好的代码，我原来写的都是什么鬼
int wiggleMaxLength(vector<int> nums) {
	int n = nums.size();
	if (n == 0) return 0;
	int up = 1, down = 1;
	for (int i = 1; i < n; i++) {
		if (nums[i] > nums[i - 1]) up = down + 1; 
		else if(nums[i] < nums[i - 1]) down = up + 1;
	}
	return max(down,up);
}

