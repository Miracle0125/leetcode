#include<vector>
#include<string>
using namespace std;

bool check(string s) {
	if (s.length() > 1 && s[0] == '0') return false;
	int m = 1,sum=0;
	for (int i = s.length()-1; i >=0; i--)	{
		sum += (s[i]-48) * m;
		m *= 10;
	}
	return sum <= 255;
}

vector<string> restoreIpAddresses(string s,int n) {
	int len = s.length();
	vector<string> ret, map;
	if (n == 1) {
		if (check(s)) {
			return vector<string>{s};
		}
	}
	else {
		for (int i = 1; i < 4; i++)
		{
			if (len - i >= n - 1 && len - i <= (n - 1) * 3) {
				if (check(s.substr(0, i))) {
					map = restoreIpAddresses(s.substr(i, len), n - 1);
					if (map.size()) {
						for (int j = 0; j < map.size(); j++)
							map[j].insert(0, s.substr(0, i) + ".");
						ret.insert(ret.end(), map.begin(), map.end());
					}
				}
			}
		}
	}
	return ret;
}

vector<string> restoreIpAddresses(string s) {
	return restoreIpAddresses(s, 4);
}