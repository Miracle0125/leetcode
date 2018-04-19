#include"common.h"
#include<vector>
using namespace std;


//better
bool wordBreak(string s, vector<string> & dict) {
	vector<int> f(s.length() + 1, 0);
	f[0] = 1;
	for (int i = 1; i <= s.length(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (f[j] && find(dict.begin(), dict.end(), s.substr(j, i - j)) != dict.end())
				f[i] = 1;
		}
	}
	
	return f[s.length()];
}