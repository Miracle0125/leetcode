#include"common.h"
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

//better
int removeDuplicates(vector<int>& nums) {
	int len = nums.size();
	for (int i = 0; i < len;)
	{
		if (i>1&&nums[i] == nums[i - 2]) {
			nums.erase(nums.begin() + i);
			len--;
			continue;
		}
		i++;
	}
	return len;
}

//me
int removeDuplicates2(vector<int>& nums) {
	int m1 = INT_MIN, m2 = INT_MIN,len=nums.size();
	for (int i = 0; i < len;)
	{

		if (nums[i] == m1) {
			if (nums[i] == m2) {
				nums.erase(nums.begin() + i);
				len--;
				continue;
			}else{
				m2 = nums[i];
			}
		}
		else m1 = nums[i];
		i++;
	}
	return len;
}
//
//int main() {
//	cout << 500 + 12 + 11 + 13 - 23 + 3 + 8 + 40 - 264 - 79 + 12 - 16 + 18 - 2 + 48 + 16 + 2 + 12 - 16 + 17 + 13 + 29 + 11 + 10 + 200 + 11.5 << "   " << 300 - 79 + 12 - 16 + 18 - 2 + 48 + 16 + 2 + 12 - 16 + 17 + 13 + 29 + 11 + 10 + 200 + 11.5 << endl;
//	return 1;
//}