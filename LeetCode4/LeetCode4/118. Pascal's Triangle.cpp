
#include"common.h"
#include<vector>
using namespace std;

//beats     8.7%  .....
vector<vector<int>> generate(int n) {
	vector<vector<int>> ret;
	if (n) {
		ret.push_back(vector<int>{1});
		for (int i = 1; i < n; i++) {
			vector<int> v(2,1);
			for (int j = 1; j < ret[i - 1].size(); j++)
				 v.insert(v.begin()+1,ret[i - 1][j - 1] + ret[i - 1][j]);
			ret.push_back(v);
		}
	}
	return ret;
}