#include<vector>
using namespace std;


// 两个边界一起收缩
int trap(vector<int>& height) {
	int peak_l = 0,peak_r=0, l = 0, r = height.size() - 1,res = 0;
	while (l <= r) {
		if (height[l] < height[r]) {
			if (height[l] <= peak_l) res += peak_l - height[l];
			else peak_l = height[l];
			l++;
		}else{
			if (height[r] <= peak_r) res += peak_r - height[r];
			else peak_r = height[r];
			r--;
		}
	}
	return res;
}