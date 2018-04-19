#include<vector>
#include"common.h"
#include<stack>
using namespace std;


//other,very nice  code
vector<int> inorderTraversal(TreeNode* root) {
	vector<int> ret;
	stack<TreeNode*> s;
	TreeNode* p = root;
	while (p||!s.empty()) {
		while (p) {
			s.push(p);
			p = p->left;
		}
		p = s.top()->right;
		ret.push_back(s.top()->val);
		s.pop();
	}
	return ret;
}
