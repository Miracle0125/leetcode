#include<vector>
#include<iostream>
using namespace std;




int removeDuplicates(vector<int>& nums) {
	int n = nums.size(),p = 1;
	if (n < 2) return n;
	for (int i = 1; i < n; i++)
	{
		if (nums[i] != nums[i - 1]) nums[p++] = nums[i];
	}
	return p;
}