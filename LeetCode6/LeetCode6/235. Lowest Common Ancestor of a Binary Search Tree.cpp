#include"common.h"
#include<algorithm>
using namespace std;

class _235 {

	//me
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root->val >= min(q->val, p->val) && root->val <= max(p->val, q->val)) return root;
		if (p->val < root->val) return lowestCommonAncestor(root->left, p, q);
		if (p->val > root->val) return lowestCommonAncestor(root->right, p, q);
	}

	//better
	TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
		while ((root->val - p->val)*(root->val - q->val) > 0)
			root = p->val < root->val ? root->left : root->right;
		return root;
	}
};
