#include<vector>
#include"common.h"
using namespace std;


//”¶∏√”√queue
vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> ret;
	if (root) {
		vector<TreeNode*> s{ root }, cache;
		while (!s.empty()) {
			vector<int> v;
			while (!s.empty()) {
				v.push_back(s[0]->val);
				if (s[0]->left) cache.push_back(s[0]->left);
				if (s[0]->right) cache.push_back(s[0]->right);
				s.erase(s.begin());
			}
			ret.push_back(v);
			s = cache;
			cache.clear();
		}
	}
	return ret;
}