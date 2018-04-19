#include"common.h"
using namespace std;


//���ø�׼ȷ���׶�������Ϊʲô�ܵú���һ���죿
//bool hasPathSum2(TreeNode* root, int sum) {
//	if (!root) return false;
//	sum -= root->val;
//	if (!root->left&&!root->right && !sum) return true;
//	return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
//}
//
//
////me
bool impl(TreeNode* root, int sum) {
	if (!root) return !sum;
	sum -= root->val;
	return (root->left ? impl(root->left, sum) : !sum && !root->right)
		|| (root->right ? impl(root->right, sum) : !sum && !root->left);
}

bool hasPathSum(TreeNode* root, int sum) {
	if (!root) return false;
	return impl(root, sum);
}