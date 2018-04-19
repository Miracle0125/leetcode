#include<vector>
#include"common.h"
#include<iostream>
using namespace std;

//min start with 1
vector<vector<int>> combine(int min,int n,int k){
	vector<vector<int>> ret;
    if (k == 1) 
		for (int i = min; i <= n; i++)
			ret.push_back(vector<int>{i});
	else {
		for (int i = min; i <= n - k + 1; i++)
		{
			vector<vector<int>> son = combine(i + 1, n, k - 1);
			for (int j = 0; j < son.size(); j++)
				son[j].insert(son[j].begin(), i);
			ret.insert(ret.end(), son.begin(), son.end());
		}
	}
	return ret;
}

vector<vector<int>> combine(int n, int k) {
	vector<vector<int>> ret;
	if(k)
	 ret = combine(1,n,k);
	return ret;
}