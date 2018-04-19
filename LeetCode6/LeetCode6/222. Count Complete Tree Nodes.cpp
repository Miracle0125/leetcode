
#include"common.h"
#include<vector>
#include<algorithm>

using namespace std;



//��Ȼ���˵� �����ǿ찡���ٷ�֮60��
int countNodes(TreeNode* root) {
	if (!root) return 0;
	int h = 0, right_h = 0;
	auto p = root;
	for (; p->left; h++, p = p->left);
	p = root;
	for (; p->right; right_h++, p = p->right);
	//this means the tree is full
	if (right_h == h) return pow(2, h + 1) - 1;
	//start binary search
	int l = 0, r = pow(2, h) - 1, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		p = root;
		for (int i = h-1; i >= 0; i--)
		{
			if ((mid >>i) & 1)
				p = p->right;
			else p = p->left;
		}
		if (p) {
			if (r - l <= 1) 
				return pow(2, h) + l;
			l = mid;
		}
		else r = mid;
	}
}

//97%  �ֲ���˹
//ħ������
int countNodes2(TreeNode* root) {
	if (!root) return 0;
	TreeNode *temp = root;
	int height = 0, count = 0, level;
	while (temp) {
		temp = temp->left;
		height++;
	}
	temp = root;
	level = height - 2;
	while (level >= 0) {
		TreeNode *left = temp->left;
		for (int i = 0; i < level; i++) {
			left = left->right;
		}
		if (left) {
			temp = temp->right;
			count += (1 << level);
		}
		else temp = temp->left;
		level--;
	}
	if (temp) count++;
	return (1 << (height - 1)) + count - 1;
}