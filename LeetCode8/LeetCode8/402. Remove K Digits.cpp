

#include"common.h"

//me 7ms
string removeKdigits(string num, int k) {
	int n = num.size();
	for (int j = 0; j < k; j++) {
		int i = 0;
		for (; i < n - 1; i++)
		{
			if (num[i] > num[i + 1]) { num.erase(num.begin() + i); break; }
		}
		if (i == n - 1) num.erase(--num.end());
		else if (!i) while (num[i] == '0') { num.erase(num.begin() + i); n--; }
		if (--n == 0) return "0";
	}
	return num;
}
//best 3ms
string removeKdigits2(string num, int k) {
	string ret;
	int keep = num.size() - k;
	for (auto c : num) {
		while (k && !ret.empty() && ret.back() > c) {
			ret.pop_back();
			--k;
		}
		ret.push_back(c);
	}
	ret.resize(keep);
	while (!ret.empty() && ret[0] == '0') ret.erase(ret.begin());
	return ret.empty() ? "0" : ret;
}

