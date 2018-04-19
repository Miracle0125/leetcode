
#include<vector>
using namespace std;


vector<int> searchRange(vector<int>& nums, int target) {
	vector<int> ret(2,-1);
	if (nums.empty()) return ret;
	if (nums[0] > target || nums[nums.size() - 1] < target) return ret;
	int l = 0, r = nums.size()-1,mid;
	while (l < r) {
		mid = (l + r) / 2;
		if ((nums[mid]) < target) 
			l = mid + 1;
		else r = mid;
	}
	if (nums[l] != target) return ret;
	else ret[0]=l;
	if (l == nums.size() - 1) { ret[1]=l; return ret; }
	r = nums.size()-1;
	while (l < r) {
		mid = (l + r) / 2 + 1;    //Ï¸Î¢²î±ð
		if ((nums[mid]) > target)
			r = mid - 1;
		else l = mid;
	}
	ret[1]=l;
	return ret;
}

//
//int main() {
//	searchRange(vector<int>{5, 7, 7, 8, 8, 10}, 8);
//	system("pause");
//}