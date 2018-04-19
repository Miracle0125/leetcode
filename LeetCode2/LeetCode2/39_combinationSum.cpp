#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

//2, 3, 4
//
//Target = 7
//
//ÿһ��ѭ������һ�㣬��ִ��3�������ѭ�������˳���������2���ҵ�'3'�������������ص���һ��ѭ����
//
//���vector�е�ÿһ��Ԫ�أ����������״�ķ�֧��

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