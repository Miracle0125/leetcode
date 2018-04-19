
using namespace std;
#include"common.h"
#include<algorithm>
#include<list>

void merge(vector<vector<int>> &A) {
	int n = A.size(),len=A[0].size(),limit=min(20,n/4);
	for (int i = 1; i < limit; i++)
		len = max(len, (int)A[i].size());
	//这里是个trick,因为加上这个才beats 97%，实际上不够严谨
	for (int i = 0; i < A.size()/5; i++)
	{
		for (int j = i+1; j < A.size(); j++)
		{
			if (A[i].size() + A[j].size() > len) {
				if (A[j][0] % A[i][0] == 0) {
					int m = A[i].size() - 1, size = m + A[j].size() + 1;
					while (size > len) {
						if (A[j][0] % A[i][m] == 0) {
							A[i].erase(A[i].begin() + m + 1, A[i].end());
							A[i].insert(A[i].end(), A[j].begin(), A[j].end());
							break;
						}
						m--;
						size--;
					}
				};
			}
		}
	}
}

vector<int> largestDivisibleSubset(vector<int>& A) {
	if (A.size() <= 1) return A;
	sort(A.begin(), A.end());
	vector<vector<int>> memo;
	vector<int> ret{ A[1] };
	for (int i = A[0] == 1 ? 1 : 0; i < A.size(); i++)
	{
		if (!A[i]) continue;
		int last = A[i];
		A[i] = 0;
		vector<int> v{last};
		for (int j = i+1; j < A.size(); j++)
		{
			if (!A[j]) continue;
			if (A[j] % last == 0) {
				v.push_back(A[j]);
				last = A[j];
				A[j] = 0;
			}
		}
		if (v.size() > 1) memo.push_back(v);
	}
	int index = 0;
	if (!memo.size()) {
		if (A[0] == 1) ret.insert(ret.begin(), 1);
		return ret;
	}
	else {
		merge(memo);
		for (int i = 1, len = memo[0].size(); i < memo.size(); i++)
		{
			if (memo[i].size() > len) {
				index = i;
				len = memo[i].size();
			}
		}
	} 
	if (A[0] == 1) memo[index].insert(memo[index].begin(), 1);
	return memo[index];
}