#include<vector>
#include"common.h"
using namespace std;

vector<vector<int>> ret;
void pathSum(TreeNode* root, int sum,vector<int> &v) {
	if (!root) return;
	v.push_back(root->val);
	if (!root->left && !root->right&&root->val == sum) {
		ret.push_back(v);
	}else{
		pathSum(root->left,sum-root->val,v);
		pathSum(root->right, sum - root->val,v);
	}
	v.erase(v.end()-1);
}


vector<vector<int>> pathSum(TreeNode* root, int sum) {
	vector<int> v;
	pathSum(root, sum, v);
	return ret;
}