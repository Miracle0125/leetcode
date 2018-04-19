#include<vector>
#include<set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
	return nums.size() > set<int>(nums.begin(), nums.end()).size();
}