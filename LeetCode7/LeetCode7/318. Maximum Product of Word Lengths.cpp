


using namespace std;
#include"common.h"
#include<algorithm>
#include<set>


static  bool cmp(string a, string b) {
	return a.size() > b.size();
}

bool no_share(vector<int> &map, string a, string b) {
	for (auto k = b.begin(); k != b.end(); k++) 
		if (map[*k - 'a']) 
			return false;
	return true;
}
int maxProduct(vector<string>& A) {
	int n = A.size(), ret = 0;
	sort(A.begin(), A.end(), cmp);
	vector<vector<int>> map(A.size(), vector<int>(26));
	for (int i = 0; i < A.size(); i++)
		for (auto j = A[i].begin(); j != A[i].end(); j++)
			map[i][*j - 'a']++;
	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++) {
			int product = A[i].size()*A[j].size();
			if (product > ret) {
				if (no_share(map[j], A[j], A[i]))
					ret = max(ret, (int)product);
			}
			else  break;
		}
	return ret;
}

	//bit,  É§²Ù×÷
int maxProduct2(vector<string>& words) {
	vector<int> mask(words.size());
	int result = 0;
	for (int i = 0; i<words.size(); ++i) {
		for (char c : words[i])
			mask[i] |= 1 << (c - 'a');
		for (int j = 0; j<i; ++j)
			if (!(mask[i] & mask[j]))
				result = max(result, int(words[i].size() * words[j].size()));
	}
	return result;
}

//for (int i = 0; i < A.size(); i++)
//{
//	for (int j = A.size() - 1; j >i; j--)
//	{
//		for (auto k = A[j].begin(); k != A[j].end(); k++) {
//			if (map[i][*k - 'a'])
//			{
//				A.erase(A.begin() + j);
//				j--;
//				break;
//			}
//		}
//	}
//}