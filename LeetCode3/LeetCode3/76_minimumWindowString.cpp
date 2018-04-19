#include<string>
#include<algorithm>
#include<vector>
using namespace std;


//267/268  TimeLimitExceeded
//复杂度太高了，每次遍历到map里的字母
string minWindow(string s, string t) {
	vector<int> map(128, 0),copy;
	int m = s.length(), l = 0, r, counter = t.length(), cache = counter, len = INT_MAX, minl = 0;
	for (char c : t) map[c]++;
	copy = map;
	for (; l < m;l++)
	{
		if (map[s[l]]==0) continue;
		r = l;
		for (; r<m&&r - l <= len&&counter; r++)
			if (map[s[r]]-- > 0) counter--;
		if (r - l < len&&counter==0) {
			len = r - l;
			minl = l;
		}
		counter = cache;
		map = copy;
	}
	return len == INT_MAX ? "" : s.substr(minl, len);
}

//
//S = "ADOBECODEBANC"
//T = "ABC"
//魔法一般的代码，因为end 和 begin 最多遍历s一次  所以时间复杂度为O(2m)   ，m=s.length()

string minWindow2(string s, string t) {
	vector<int> map(128, 0);
	for (auto c : t) map[c]++;
	int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
	while (end<s.size()) {
		//只要不是T里的字母全部减一，结果都小于0
		if (map[s[end++]]-->0) counter--; //in t
		while (counter == 0) { //valid
			if (end - begin<d)  d = end - (head = begin);
			//如果有多余的重复的字母会跳过
			if (map[s[begin++]]++ == 0) counter++;  //make it invalid
		}
	}
	return d == INT_MAX ? "" : s.substr(head, d);
}