#include<vector>
#include"common.h"
#include<stack>
using namespace std;

bool isSameTree(TreeNode* p, TreeNode* q) {
	if (!p || !q) return p == q;
	return p->val == q->val&&isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}