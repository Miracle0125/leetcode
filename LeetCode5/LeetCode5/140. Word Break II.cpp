


#include"common.h"
#include<vector>
#include<algorithm>

using namespace std;



vector<string> wordBreak(string s, vector<string>& A) {
	vector<string> ret{};
	for (int i = 0; i < s.size(); i++)
	{
		string word = s.substr(0, i + 1);
		if (find(A.begin(), A.end(), word) != A.end()) {
			vector<string> v;
			if (i == s.size() - 1) v = {word};
			else {
				v = wordBreak(s.substr(i + 1, s.size()), A);
				for (int i = 0; i < v.size(); i++)
					v[i].insert(0, word + " ");
			}
			if (!v.empty()) ret.insert(ret.begin(), v.begin(), v.end());
		}
	}
	return ret;
}

int main() {
	vector<string> v = { "cat", "cats", "and", "sand", "dog" };
	auto ret=wordBreak("catsanddog", v);
	return 0;
}