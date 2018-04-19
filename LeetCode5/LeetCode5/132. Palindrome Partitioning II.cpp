#include"common.h"
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


//如果存在一个palindrome，则会在其尾部更新cuts，后续会把这个影响递推到尾部
//better
int minCut(string s) {
	int n = s.size();
	vector<int> cut(n + 1, 0);  // number of cuts for the first k characters
	for (int i = 0; i <= n; i++) cut[i] = i - 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; j++) // odd length palindrome
			cut[i + j + 1] = min(cut[i + j + 1], 1 + cut[i - j]);

		for (int j = 1; i - j + 1 >= 0 && i + j < n && s[i - j + 1] == s[i + j]; j++) // even length palindrome
			cut[i + j + 1] = min(cut[i + j + 1], 1 + cut[i - j + 1]);
	}
	return cut[n];
}

//int minCut(string s) {
//	int minSize = INT_MAX;
//	vector<vector<string>> v = partition(s);
//	for (int i = 0; i < v.size(); i++)
//	{
//		minSize = min(minSize, (int)(v[i].size() - 1));
//	}
//	return minSize;
//}
//ababa babababababababababcbabababababababababababa
