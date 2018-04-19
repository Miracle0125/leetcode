
#include<vector>
#include"common.h"
using namespace std;



//me  beats 71%
TreeNode* sortedArrayToBST(vector<int>& nums, TreeNode* root,int l,int r) {
	if (l!=r) {
		int mid = (r + l) / 2;
		root = new TreeNode(nums[mid]);
		if(l!=mid)
			root->left = sortedArrayToBST(nums, root, l, mid - 1);
		root->right = sortedArrayToBST(nums, root, mid + 1, r);
		return root;
	}else return new TreeNode(nums[l]);
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
	if (nums.empty()) return NULL;
	return sortedArrayToBST(nums,NULL,0, nums.size()-1);
}