#include"common.h"
#include<vector>
using namespace std;

class _129 {
public:
	int ret = 0;
	void sumNumbers(TreeNode* root, int n) {
		if (!root->left && !root->right) ret += n * 10 + root->val;
		else {
			if (root->left)
				sumNumbers(root->left, n * 10 + root->val);
			if (root->right)
				sumNumbers(root->right, n * 10 + root->val);
		}
	}

	int sumNumbers(TreeNode* root) {
		if (!root) return 0;
		sumNumbers(root, 0);
		return ret;
	}
};
