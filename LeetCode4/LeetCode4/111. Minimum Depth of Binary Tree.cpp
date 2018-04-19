
#include"common.h"
#include<algorithm>
using namespace std;


//better  代码其实差不多，不过有更准确的表达
//int minDepth2(TreeNode* root) {
//	if (!root) return 0;
//	int l = minDepth(root->left);
//	int r = minDepth(root->right);
//	return (!l || !r) ? l + r + 1 : min(l,r)+1;
//}
//
//
////me
int minDepth(TreeNode* root) {
	if (!root) return 0;
	int l = minDepth(root->left);
	int r = minDepth(root->right);
	return !l ? r + 1 : (!r ?l + 1:(min(l, r) + 1));
}