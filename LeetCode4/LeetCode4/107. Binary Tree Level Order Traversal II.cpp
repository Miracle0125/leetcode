#include<vector>
#include"common.h"
#include<stack>
using namespace std;


vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	bool direct = true;
	vector<vector<int>> ret;
	if (root) {
		vector<TreeNode*> s{ root }, cache;
		while (!s.empty()) {
			vector<int> v;
			while (!s.empty()) {
				if (direct) v.push_back(s[0]->val); else v.insert(v.begin(), s[0]->val);
				if (s[0]->left) cache.push_back(s[0]->left);
				if (s[0]->right) cache.push_back(s[0]->right);
				s.erase(s.begin());
			}
			direct = !direct;
			ret.push_back(v);
			s = cache;
			cache.clear();
		}
	}
	return ret;
}

