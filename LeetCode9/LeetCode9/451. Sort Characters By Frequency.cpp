

#include"common.h"

string frequencySort(string s) {
	string r;
	if (s == "") return r;
	vector<string> v('~' + 1);
	for (const auto c : s)
		v[c].push_back(c);
	sort(v.begin(), v.end(), [](string a,string b) { return a.size() > b.size(); });
	for (auto i : v) 
		r+=i;
	return r;
}