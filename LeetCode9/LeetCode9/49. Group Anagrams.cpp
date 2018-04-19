

#include"common.h"



vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string>> r;
	if (strs.empty()) return r;
	vector<pair<string, vector<int>>> m;
	sort(strs.begin(), strs.end());
	for (int i = 0; i < strs.size(); i++)
	{
		m.push_back({ strs[i],vector<int>(26) });
		auto p = m.end() - 1;
		for (auto c : strs[i])
			p->second[c - 'a']++;
	}
	auto is_valid = [](vector<int> &a, vector<int> &b) {
		for (int i = 0; i < a.size(); i++)
			if (a[i] != b[i]) return false;
		return true;
	};
	for (; !m.empty();) {
		vector<string> group = {};
		for (int i = 1; i < m.size() && m[i].second.size() == m[0].second.size(); i++)
		{
			if (is_valid(m[0].second, m[i].second)) {
				group.push_back(m[i].first);
				m.erase(m.begin() + i--);
			}
		}
		group.push_back(m[0].first);
		r.push_back(group);
		m.erase(m.begin());
	}
	return r;
}


