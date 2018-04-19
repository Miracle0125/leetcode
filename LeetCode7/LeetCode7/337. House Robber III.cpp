



using namespace std;
#include"common.h"
#include<map>
#include<algorithm>



void rob(TreeNode* root,map<TreeNode*,int> &map){
	if (root) {
		rob(root->left, map), rob(root->right,map);
		int second = map[root->left] + map[root->right];
		int third = (root->left ? map[root->left->left]+ map[root->left->right] : 0)
			+ (root->right ? map[root->right->left]+ map[root->right->right] : 0);
		map[root] = max(root->val + third, second);
	}
}

int rob(TreeNode* root) {
	map<TreeNode*, int> map;
	map[nullptr] = 0;
	rob(root, map);
	return map[root];
}
//
//
//int tryRob(TreeNode* root, int& l, int& r) {
//	if (!root)
//		return 0;
//
//	int ll = 0, lr = 0, rl = 0, rr = 0;
//	l = tryRob(root->left, ll, lr);
//	r = tryRob(root->right, rl, rr);
//
//	return max(root->val + ll + lr + rl + rr, l + r);
//}
//
//int rob(TreeNode* root) {
//	int l, r;
//	return tryRob(root, l, r);
//}