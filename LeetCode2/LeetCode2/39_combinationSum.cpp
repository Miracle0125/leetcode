#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//2, 3, 4
//
//Target = 7
//
//每一个循环加深一层，当执行3层后不满足循环条件退出，跳到第2层找到'3'，符合条件返回到第一层循环。
//
//针对vector中的每一个元素，都有许多树状的分支。

void impl(vector<int> &candidates,vector<int> &combination,vector<vector<int>> &res,int target,int pos) {
	if (!target) {
		res.push_back(combination);
		return;
	}
	for (int i = pos; i < candidates.size()&&target>=candidates[i]; i++)
	{
		combination.push_back(candidates[i]);
		impl(candidates, combination, res, target-candidates[i], i);
		combination.pop_back();
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	sort(candidates.begin(), candidates.end());
	vector<vector<int> > res;
	vector<int> combination;
	impl(candidates, combination, res, target, 0);
	return res;
}






//void combinationSum(vector<int> &candidates, int target, vector<vector<int> > &res, vector<int> &combination, int begin) {
//	if (!target) {
//		res.push_back(combination);
//		return;
//	}
//	for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
//		combination.push_back(candidates[i]);
//		combinationSum(candidates, target - candidates[i], res, combination, i);
//		combination.pop_back();
//	}
//}
//
//vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//	sort(candidates.begin(), candidates.end());
//	vector<vector<int> > res;
//	vector<int> combination;
//	combinationSum(candidates, target, res, combination, 0);
//	return res;
//}



//int main() {
//	if (0) cout << "true";
//	system("pause");
//}