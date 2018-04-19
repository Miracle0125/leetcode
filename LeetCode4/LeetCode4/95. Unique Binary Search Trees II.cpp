

#include"common.h"
#include<iostream>
using namespace std;


//这么长的代码差不多一次过，简直爽过吸大麻
int n=0;
TreeNode* symmetreTree(TreeNode* head,int val) {
	if (!head) return NULL;
	TreeNode* copy = new TreeNode(val);
	if (head->left)
		copy->right = symmetreTree(head->left, n - (head->left->val - 1));
	if (head->right)
		copy->left = symmetreTree(head->right, n - (head->right->val - 1));
	return copy;
}

vector<TreeNode*> generateTrees(int l,int r,int val) {
	vector<TreeNode*> ret,v,v1,v2;
	if (l < r) {
		for (int i = l; i < val; i++) {
			v2 = generateTrees(l, val - 1, i);
			v.insert(v.end(), v2.begin(),v2.end());
		}
		for (int i = val + 1; i <= r; i++) {
			v2 = generateTrees(val+1, r, i);
			v1.insert(v1.end(), v2.begin(), v2.end());
		}
		if (v.empty()||v1.empty()) {
			bool mark = v.empty();
			v = mark ? v1 : v;
			for (int i = 0; i < v.size(); i++)
			{
				TreeNode* head = new TreeNode(val);
				mark ? head->right = v[i] : head->left = v[i];
				ret.push_back(head);
			}
		}else 
			for (int i = 0; i < v.size(); i++)
			{
				for (int j = 0; j < v1.size(); j++)
				{
					TreeNode* head = new TreeNode(val);
					head->left = v[i];
					head->right = v1[j];
					ret.push_back(head);
				}
			}
	}
	else if(l==r) ret.push_back(new TreeNode(val));
	return ret;
}

vector<TreeNode*> generateTrees(int num) {
	n = num;
	vector<TreeNode*> ret,cache;
	if (n > 1) {
		//int border = num & 1 ? n / 2 + 1 : n / 2;
		for (int i = 1; i <= n / 2; i++)
		{
			cache = generateTrees(1,n,i);
			ret.insert(ret.end(), cache.begin(), cache.end());
			int size = cache.size();
			for (int j = 0; j < size ;j++)
				cache.push_back(symmetreTree(cache[j],n-cache[j]->val+1));
			ret.insert(ret.begin(), cache.begin() + size, cache.end());
		}
		if (n & 1) {
			cache = generateTrees(1, n, n/2+1);
			ret.insert(ret.end(), cache.begin(), cache.end());
		}
	}
	else if(n==1) ret.push_back(new TreeNode(1));
	return ret;
 }

TreeNode* clone(TreeNode* root) {
	if (root == nullptr)
		return nullptr;
	TreeNode* newroot = new TreeNode(root->val);
	newroot->left = clone(root->left);
	newroot->right = clone(root->right);
	return newroot;
}
vector<TreeNode *> generateTrees2(int n) {
	if (!n) return vector<TreeNode*> {};
	vector<TreeNode *> res(1, nullptr);
	for (int i = 1; i <= n; i++) {
		vector<TreeNode *> tmp;
		for (int j = 0; j<res.size(); j++) {
			TreeNode* oldroot = res[j];
			TreeNode* root = new TreeNode(i);
			TreeNode* target = clone(oldroot);
			root->left = target;
			tmp.push_back(root);

			if (oldroot != nullptr) {
				TreeNode* tmpold = oldroot;
				while (tmpold->right != nullptr) {
					TreeNode* nonroot = new TreeNode(i);
					TreeNode *tright = tmpold->right;
					tmpold->right = nonroot;
					nonroot->left = tright;
					TreeNode *target = clone(oldroot);
					tmp.push_back(target);
					tmpold->right = tright;
					tmpold = tmpold->right;
				}
				tmpold->right = new TreeNode(i);
				TreeNode *target = clone(oldroot);
				tmp.push_back(target);
				tmpold->right = nullptr;
			}
		}
		res = tmp;
	}
	return res;
}

//int main() {
//vector<TreeNode*> v =  generateTrees2(12);
////v = generateTrees2(12);
//return 1;
//}