
#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<string>
using namespace std;

    int longestConsecutive(vector<int>& nums) {
		unordered_map<int,int> map;
		for (int i : nums) {
			if (map.find(i) == map.end()) {
				int l = map.find(i - 1) == map.end() ? map.at(i - 1) : 0;
				int r= map.find(i + 1) == map.end() ? map.at(i + 1) : 0;
				int sum = l + r + 1;

				map.emplace(i, sum);
				if(r!=0)
					map.emplace(i + r, sum);
				if (l != 0)
					map.emplace(i - l, sum);

			}
		}
    }

	int main() {

	int l=	longestConsecutive(vector<int>{100,4,200,1,3,2});
		return 1;
	}