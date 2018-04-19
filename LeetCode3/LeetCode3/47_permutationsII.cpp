#include<vector>
#include<unordered_map>

using namespace std;

vector<vector<int>> insert2(vector<vector<int>> v, int t) {
	for (int i = 0; i < v.size(); i++)
	{
		v[i].insert(v[i].begin(), t);
	}
	return v;
}

vector<vector<int>> permuteUniqueImpl(vector<int> nums) {
	if (nums.size() == 2)if (nums[0] == nums[1]) { return vector<vector<int>> {nums}; }
	else return vector<vector<int>>{ nums, { nums[1],nums[0] }};
	vector<vector<int>> temp, ret;
	vector<int> c = nums;
	unordered_map<int, int> dict;
	for (int i = 0; i < nums.size(); i++)
	{
		if (dict.find(nums[i]) != dict.end()) continue;
		c.erase(c.begin() + i);
		temp = insert2(permuteUniqueImpl(c), nums[i]);
		ret.insert(ret.end(), temp.begin(), temp.end());
		c = nums;
		dict[nums[i]] = 0;
	}
	return ret;
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
	if (nums.size() == 0) return vector<vector<int>>{ {}};
	if (nums.size() == 1) return vector<vector<int>>{ {nums}};
	return   permuteUniqueImpl(nums);
}

//int main() {
//	permuteUnique(vector<int>{1,1,2,2});
//	system("pause");
//}