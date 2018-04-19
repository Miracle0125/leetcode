

#include"common.h"
#include<vector>
#include<sstream>
using namespace std;


vector<string> binaryTreePaths(TreeNode* root) {
	vector<string> ret{}, v{};
	if (root) {
		v=binaryTreePaths(root->left);
		ret.insert(ret.end(),v.begin(),v.end());
		v = binaryTreePaths(root->right);
		ret.insert(ret.end(), v.begin(), v.end());
		if(ret.size())
			for (auto& i : ret) 
				i.insert(0, itoa(root->val) + "->");
		else ret.push_back(itoa(root->val));
	}
	return ret;
}

//int main() {
//	
//	auto ret=buildTree(vector<int>{2, 1, 3, 4},1);
//	auto v=binaryTreePaths(ret);
//	return 0;
//}