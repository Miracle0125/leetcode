#include<vector>
#include<iostream>
using namespace std;

int searchInsert(vector<int>& nums, int t) {
	int r = nums.size(),l=0,pos;
	while (l <= r) {
		pos = (l + r) / 2;
		if (pos == r) return pos;
		if (t > nums[pos]) {
			l = pos + 1;
		}else if(t<=nums[pos]){
			if(t<=nums[pos-1]){
				r = pos - 1;
			}
			else return pos;
		}
	}
	return pos;
}

//经典解法，解决了pos的越界问题
int searchInsert2(vector<int>& nums, int target) {
	int low = 0, high = nums.size() - 1;

	// Invariant: the desired index is between [low, high+1]
	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (nums[mid] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}

	// (1) At this point, low > high. That is, low >= high+1
	// (2) From the invariant, we know that the index is between [low, high+1], so low <= high+1. Follwing from (1), now we know low == high+1.
	// (3) Following from (2), the index is between [low, high+1] = [low, low], which means that low is the desired index
	//     Therefore, we return low as the answer. You can also return high+1 as the result, since low == high+1
	return low;
}