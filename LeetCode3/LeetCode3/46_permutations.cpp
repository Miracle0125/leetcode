#include<vector>
using namespace std;


//×Ô¼ºÐ´µÄ
vector<vector<int>> insert(vector<vector<int>> v,int t) {
	for (int i = 0; i < v.size(); i++)
	{
		v[i].insert(v[i].begin(), t);
	}
	return v;
}

vector<vector<int>> permuteImpl(vector<int> nums) {
	if (nums.size() == 2) return vector<vector<int>>{ nums, { nums[1],nums[0] }};
	vector<vector<int>> temp,ret;
	vector<int> c = nums;
	for (int i = 0; i < nums.size(); i++)
	{
		c.erase(c.begin() + i);
		temp = insert(permuteImpl(c),nums[i]);
		ret.insert(ret.end(), temp.begin(), temp.end());
		c = nums;
	}
	return ret;
}

vector<vector<int>> permute(vector<int>& nums) {
	if(nums.size()==0) return vector<vector<int>>{ {}};
	if (nums.size() == 1) return vector<vector<int>>{ {nums}};
	return   permuteImpl(nums);
}

//int main() {
//	permute(vector<int>{1,2,3,4,5});
//	system("pause");
//}

