
#include"common.h"
#include<stack>
using namespace std;

//сп©с
bool isSymmetric(TreeNode* l, TreeNode* r) {
	if (!l && !r) return true;
	if ((l!=NULL ? r==NULL : r!=NULL) || l->val != r->val) return false;
	return isSymmetric(l->left, r->right) && isSymmetric(l->right, r->left);
}

bool isSymmetric(TreeNode* root) {
	return !root|| isSymmetric(root->left, root->right);
}