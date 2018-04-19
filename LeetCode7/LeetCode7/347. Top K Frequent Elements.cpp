


using namespace std;
#include"common.h"


vector<int> topKFrequent(vector<int>& A, int k) {
	int n = A.size();
	vector<vector<int>> bucket(n + 1);
	map<int, int> M;
	vector<int> ret;
	for (int i : A)	M[i]++;
	for (auto i = M.begin(); i != M.end(); i++) bucket[i->second].push_back(i->first);
	for (auto i = n; i >=0 && ret.size() < k; i--) if (bucket[i].size()) ret.insert(ret.end(),bucket[i].begin(),bucket[i].end());
	return ret;
}
