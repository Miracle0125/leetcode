



#include"common.h"


int countBinarySubstrings(string s) {
	int r = 0, n = s.size(), zeros = 0, ones = 0, i = 1;
	if (n) {
		int &count = ones, &other = zeros;
		if (s[0] == '1') {
			ones++;
		}
		else {
			zeros++;
			swap(count, other);
		}
		for (; i < n; i++) {
			if (s[i] == s[i - 1])
				count++;
			else {
				other++;
				break;
			}
		}
		swap(count, other);
		for (i++; i < n; i++)
		{
			if (s[i] == s[i - 1]) {
				count++;
			}
			else {
				r += min(ones, zeros);
				swap(count, other);
				count = 1;
			}
		}
	}
	return r + min(zeros, ones);
}

//¿É¶ÁÐÔÇ¿
class Solution_696 {
public:
	int countBinarySubstrings(string s) {
		vector<int> rec;
		int count = 1;
		for (int i = 1, n = s.size(); i <= n; ++i) {
			if (s[i] == s[i - 1]) {
				++count;
			}
			else {
				rec.push_back(count);
				count = 1;
			}
		}
		int res = 0;
		for (int i = 1, n = rec.size(); i<n; ++i) {
			res += min(rec[i - 1], rec[i]);
		}
		return res;
	}
};