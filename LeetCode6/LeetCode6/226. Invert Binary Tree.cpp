
#include"common.h"
using namespace std;

//�ӿ�����Ŀ��д������ύͨ������3���ӣ��Ⲩ��˵��

//�ܵĲ�����
TreeNode* invertTree(TreeNode* root) {
	if (root) {
		invertTree(root->left);
		invertTree(root->right);
		swap(root->left, root->right);
	}
	return root;
}