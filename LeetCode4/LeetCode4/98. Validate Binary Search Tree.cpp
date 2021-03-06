#include<vector>
#include"common.h"
using namespace std;

bool isValidBST(TreeNode* root, long minVal, long maxVal) {
	if (!root) return true;
	if (root->val >= maxVal || root->val <= minVal) return false;
	return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);
}

 bool isValidBST(TreeNode* root) {
	return isValidBST(root, LONG_MIN, LONG_MAX);
}







