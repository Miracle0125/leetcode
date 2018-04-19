#include<vector>
#include<algorithm>
using namespace std;



//我觉得我想一辈子也想不出这种代码....
vector<vector<int> > subsets(vector<int> &S) {
	sort(S.begin(), S.end());
	int elem_num = S.size();
	int subset_num = pow(2, elem_num);
	vector<vector<int> > subset_set(subset_num, vector<int>());
	for (int i = 0; i < elem_num; i++)
		for (int j = 0; j < subset_num; j++)
			if ((j >> i) & 1)
				subset_set[j].push_back(S[i]);
	return subset_set;
}