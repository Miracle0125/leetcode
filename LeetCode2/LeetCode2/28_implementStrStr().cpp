#include<string>
#include<algorithm>
using namespace std;

int strStr(string s, string t) {
	int m = s.length(), n = t.length();
	if (!n) return 0;
	for (int i = 0; i < m-n+1; i++)
	{
		int j = 0;
		for (; j < n; j++)
			if (s[i + j] != t[j])
				break;
		if (j == n) return i;
	}
	return -1;
}