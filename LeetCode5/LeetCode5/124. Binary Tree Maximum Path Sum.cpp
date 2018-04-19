#include"common.h"
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class _124 {
	int ret = INT_MIN;
	int impl(TreeNode* root) {
		if (!root) return 0;
		int maxLeft = max(0, impl(root->left));
		int maxRight = max(0, impl(root->right));
		//return max(maxLeft, maxRight) + root->left ? root->left->val:0 +root->right ? root->right->val:0;
		ret = max(ret, maxLeft + maxRight + root->val);
		return max(maxLeft, maxRight) + root->val;
	}
	int maxPathSum(TreeNode* root) {
		impl(root);
		return ret;
	}
};

