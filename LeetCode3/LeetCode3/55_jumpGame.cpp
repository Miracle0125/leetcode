#include<vector>
#include<algorithm>
using namespace std;




//时间复杂度太高......
bool jump(vector<int>& nums,int pos){
	for (int i = nums[pos]; i >= 1; i--)
	{
		if(pos + i >= nums.size()-1 || nums[pos + i] != 0 && jump(nums, pos + i))
			return true;
	}
	return false;
}

//1 2 3 0 4 1 0 2 0 4 1 2 0 1
bool canJump(vector<int>& A) {
	int i = 0,n=A.size();
	for (int reach = 0; i < n && i <= reach; ++i) {
		//加了这条语句后运行时间反而多了6ms
		if (reach > n) return true;
		reach = max(i + A[i], reach);
	}
	return i == n;
}

bool canJump2(vector<int>& nums) {
	int reach = 0;
	//for (; i<nums.size(); i++)
	//{
	//	reach += nums[i];
	//	if (!nums[reach])reach--;
	//}
	while (reach < nums.size()&&reach>=0) {
			reach += nums[reach];
			for (int i = 1; i < nums[reach]; i++)
			{

			}
			if(reach+nums[reach]==0)
			if (!nums[reach]) { 
				reach--; 
			}
	}
	return true;
}

//int main() {
//	//canJump(vector<int>{ 3, 0, 8, 2, 0, 0, 1 });
//	//canjump(src);
//}


