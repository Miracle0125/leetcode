#include<vector>
#include<algorithm>
#include"common.h"
using namespace std;


int maxDepth(TreeNode *root, int n) {
	return !root ? n : max(maxDepth(root->left, n + 1), maxDepth(root->right, n + 1));
}

int maxDepth(TreeNode *root) {
	return !root ? 0 : max(maxDepth(root->left,1), maxDepth(root->right,1));
}
