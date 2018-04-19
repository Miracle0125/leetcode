#include<vector>
#include<iostream>
using namespace std;

int removeElement(vector<int>& nums, int val) {
	int n = nums.size(),p = 0;
	for (int i = 0; i < n; i++)
	{
		if (nums[i] != val) nums[p++] = nums[i];
	}
	return p;
}