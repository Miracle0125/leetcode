


#include"common.h"


vector<int> find_factor(int n) {
	vector<bool> f(n,true);
	vector<int> r;
	for (int i = 2; i < n; i++)
	{
		if (f[i]) {
			if (n%i == 0) r.push_back(i);
			else for (int j = 2; i*j<n; j++)
				f[i*j] = false;
		}
	}
	return r;
}

bool repeatedSubstringPattern(string s) {
	int n = s.size();
	if (n < 2) return false;
	vector<int> m(n+1,0);
	for (int i = 0; i < n; i++)
		m[i + 1] = m[i] + s[i];
	vector<int> factors = find_factor(n);
	for (auto i : factors)
	{
		for (int len = n / i, end = len - 1; end < n - len; end += len)
		{

			if (m[end + 1] - m[end - len + 1] == m[end + len + 1] - m[end + 1] && s.substr(end - len + 1, len) == s.substr(end + 1, len)) {
				if (end == n - len - 1) return true;
			}
			else break;
		}
	}
	return m[n] % n == 0 && m[n] / n == s[0];
}

//
//int main() {
//auto r=	repeatedSubstringPattern("abaabaa");
//	return 0;
//}