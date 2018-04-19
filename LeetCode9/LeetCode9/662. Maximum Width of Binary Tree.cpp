


#include"common.h"
#include<unordered_map>
int r = 1;
int widthOfBinaryTree(TreeNode* root) {
	if (!root) return 0;
	vector<vector<TreeNode*>> m{ { root } };
	unordered_map<TreeNode*, int> pos;
	pos[root] = 0;
	for (int i = 0; !m[i].empty(); i++)
	{
		m.push_back({});
		for (auto j : m[i]) {
			if (j->left) {
				m[i + 1].push_back(j->left);
				pos[j->left] = pos[j] * 2;
			}
			if (j->right) {
				m[i + 1].push_back(j->right);
				pos[j->right] = pos[j] * 2 + 1;
			}
		}
		if (m[i + 1].size() > 1) r = max(r, pos[m[i + 1].back()] - pos[m[i + 1].front()] + 1);
	}
	return r;
}

class Solution_662 {
public:
	int widthOfBinaryTree(TreeNode* root) {
		vector<int> lefts; // left most nodes at each level;
		int maxwidth = 0;
		dfs(root, 1, 0, lefts, maxwidth);
		return maxwidth;
	}
private:
	void dfs(TreeNode* node, int id, int depth, vector<int>& lefts, int& maxwidth) {
		if (!node) return;
		if (depth >= lefts.size()) lefts.push_back(id);  // add left most node
		maxwidth = max(maxwidth, id + 1 - lefts[depth]);
		dfs(node->left, id * 2, depth + 1, lefts, maxwidth);
		dfs(node->right, id * 2 + 1, depth + 1, lefts, maxwidth);
	}
};