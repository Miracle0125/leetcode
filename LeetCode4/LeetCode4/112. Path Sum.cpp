#include"common.h"
using namespace std;


//表达得更准确更易读，不过为什么跑得和我一样快？
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