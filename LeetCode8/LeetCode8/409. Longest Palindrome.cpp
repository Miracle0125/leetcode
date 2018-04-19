
#include"common.h"
#include<set>
#include<unordered_map>

int longestPalindrome(string s) {
	unordered_map<char,int> dict;
	for ( char c : s) {
		dict[c]++;
	}
	int ret = 0;
	for (auto c : dict) {
		int count = c.second;
		if (count > 1) ret += ((count & 1) == 0 ? count : count - 1);
	}
	return ret < s.size() ? ret + 1 : ret;
}

//for (const char& c : s) {
//	dict[c]++;
//}

//int main() {
//	auto r = longestPalindrome("acacsw");
//	//auto r = removeKdigits("10", 1);
//	return 1;
//}