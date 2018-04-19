

#include"common.h"
using namespace std;


int t, ret;
void kthSmallest(TreeNode* root) {
	if (root->left) kthSmallest(root->left); 
	t--;
	if (!t) { ret = root->val; return; }
	if (root->right)kthSmallest(root->right);
}

int kthSmallest(TreeNode* root, int k) {
	t = k;
	kthSmallest(root);
	return ret;
}
