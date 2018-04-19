
#include"common.h"
using namespace std;

//从看完题目到写完代码提交通过不超3分钟，这波不说了

//跑的不够快
TreeNode* invertTree(TreeNode* root) {
	if (root) {
		invertTree(root->left);
		invertTree(root->right);
		swap(root->left, root->right);
	}
	return root;
}