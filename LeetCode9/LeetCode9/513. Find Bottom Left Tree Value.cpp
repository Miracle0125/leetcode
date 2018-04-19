






#include"common.h"
#include<queue>

int findBottomLeftValue(TreeNode* root) {
	vector<vector<TreeNode*>> m{ {root} };
	for (int i = 0; !m[i].empty(); i++)
	{
		m.push_back({});
		for (auto j : m[i]) {
			if (j->left)m[i + 1].push_back(j->left);
			if (j->right)m[i + 1].push_back(j->right);
		}
	}
	return m[m.size() - 2][0]->val;
}


int findBottomLeftValue2(TreeNode* root) {
	queue<TreeNode*> queue;
	queue.push(root);
	while (!queue.empty()) {
		root = queue.front();
		queue.pop();
		//���ϸ�ھͺ�ţB�ˣ����Һ����������������¾ͽ���˳��
		if (root->right)
			queue.push(root->right);
		if (root->left)
			queue.push(root->left);
	}
	return root->val;
}

