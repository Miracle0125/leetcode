
#include<vector>
#include"common.h"
#include<algorithm>
using namespace std;



//me 
bool mark = true;
int impl(TreeNode* root) {
	if (!root) return 0;
	int l = impl(root->left);
	int r = impl(root->right);
	if (abs(l-r) > 1) mark = false;
	return max(l,r)+1;
}

bool isBalanced(TreeNode* root) {
	impl(root);
	return mark;
}



//�ҵĽⷨ��������ƣ�����������ŵ�����һ���������Ϸ��Ľڵ㣬���Ϸ�������ֱ�ӷ��ؽ��
int dfsHeight(TreeNode *root) {
	if (root == NULL) return 0;

	int leftHeight = dfsHeight(root->left);
	if (leftHeight == -1) return -1;
	int rightHeight = dfsHeight(root->right);
	if (rightHeight == -1) return -1;

	if (abs(leftHeight - rightHeight) > 1)  return -1;
	return max(leftHeight, rightHeight) + 1;
}
bool isBalanced2(TreeNode *root) {
	return dfsHeight(root) != -1;
}