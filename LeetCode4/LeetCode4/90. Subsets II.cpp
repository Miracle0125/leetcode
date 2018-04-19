#include<vector>
#include<algorithm>
#include<unordered_map>
#include"common.h"
using namespace std;


//me
vector<vector<int> > subsetsWithDup(vector<int> &A,int min,int n) {
	vector<vector<int>> ret,map;
	unordered_map<int, int> cache;
	for (int i = min; i <=A.size()-n; i++)
	{
		cache[A[i]]++;
		if (cache[A[i]] < 2) {
			if (n == 1) ret.push_back(vector<int>{A[i]});
			else {
				map = subsetsWithDup(A, i + 1, n - 1);
				for (int j = 0; j < map.size(); j++)
					map[j].insert(map[j].begin(), A[i]);
				ret.insert(ret.end(), map.begin(), map.end());
			}
		}
	}
	return ret;
}

vector<vector<int> > subsetsWithDup(vector<int> &A) {
	sort(A.begin(),A.end());
	vector<vector<int> > ret{ {} };
	for (int i = A.size(); i >= 1; i--)
	{
		vector<vector<int>> map = subsetsWithDup(A, 0, i);
		ret.insert(ret.begin(), map.begin(), map.end());
	}
	printMatrix(ret);
	 return ret;
}