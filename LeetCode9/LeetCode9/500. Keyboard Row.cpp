



#include"common.h"
#define offset(c) (c>='a'?c-'a':c-'A')
vector<string> findWords(vector<string>& A) {
	int pos[26] = { 2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3 };
	vector<string> ret;
	for (auto w : A) {
		int i = 1, row = pos[offset(w[0])];
		for (; i < w.size(); i++) {
			if (pos[offset(w[i])] != row) break;
		}
		if (i >= w.size())
			ret.push_back(w);
	}
	return ret;
}