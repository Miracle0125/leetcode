

#include"common.h"
#include<string>
#include<stdlib.h>
#include<algorithm>
#include<sstream>
using namespace std;


	string serialize(TreeNode* root) {
		string ret;
		if (root) {
			ret += root->val+",";
			vector<TreeNode*> temp{root},vec;
			while (!temp.empty()) {
				for (auto i : temp) {
					if (!i) ret += "null,";
					else {
						ret += (itoa(i->val) + ",");
						vec.push_back(i->left);
						vec.push_back(i->right);
					}
				}
				temp = vec;
				vec.clear();
			}

			for (int i = ret.size()-1; i >= 0; i--)
			{
				if (ret[i] <= '9'&&ret[i] >= '0') {
					ret.erase(ret.begin() + i + 1, ret.end());
					break;
				}
			}
		}
		return "[" + ret + "]";
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string s) {
		TreeNode* root=nullptr;
		vector<string> v = split(s.substr(1, s.size() - 2), ',');
		if (!v.empty()) {
			root = new TreeNode(atoi(v[0]));
			vector<TreeNode*> temp{root  }, vec;
			int cap = 3, i = 1,inc=0;
			while (i<v.size()) {
				for (cap = min(cap, int(v.size())); i < cap; i++)
				{
					if (v[i] == "null") vec.push_back(nullptr);
					else { vec.push_back(new TreeNode(atoi(v[i]))); inc++; }
				}
				cap += inc * 2;
				inc = 0;
				for (int j = 0, edge = temp.size(); j<edge; j++)
				{
					if (temp[j]) {
						if (j * 2 + 1 < vec.size())	temp[j]->right = vec[j * 2 + 1];
						if (j * 2 < vec.size())temp[j]->left = vec[j * 2];
					}
					else { edge -= 1; j--; }
				}
				temp = vec;
				vec.clear();
			}

		}
		return root;
	}
	//在电脑上测试是可以的，但是在leetcode上没通过？



//int main() {
//	auto i = new TreeNode(1);
//	string s = "[2,1,3]";
//	auto tree = deserialize(s);
//	auto ret=serialize(tree);
//	tree = deserialize(ret);
//	return 0;
//}

