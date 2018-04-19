
#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<string>
using namespace std;

int longestConsecutive(vector<int>& nums) {
	int ret = 0;
	unordered_map<int, int> map;
	for (int i : nums) {
		if (map.find(i) == map.end()) {
			int l = map.find(i - 1) != map.end() ? map.at(i - 1) : 0;
			int r = map.find(i + 1) != map.end() ? map.at(i + 1) : 0;
			int sum = l + r + 1;
			ret = max(ret, sum);
			map.emplace(i, sum);
			map[i + r] = sum;
			map[i - l] = sum;
		}
	}
	return ret;
}

//int main() {
//
//	int l = longestConsecutive(vector<int>{1,2,0,1});
//	return 1;
//}