#include"common.h"
using namespace std;


TreeNode* p;
void flatten(TreeNode* root) {
	if (!root) return;
	flatten(root->left);
	flatten(root->right);
	root->right = p;
	root->left = NULL;
	p = root;
}