
#include<vector>
#include"common.h"
#include<iostream>
using namespace std;

//vector<TreeNode*> v;
//bool isValid(TreeNode* root) {
//	return (!root->left || root-> val > root->left->val) && (!root->right || root->val < root->right->val);
//}
//
//void searchWrong(TreeNode* root, TreeNode* head,bool isLeft,int level){
//	if (!root) return;
//	if (root->left&&root->val < root->left->val) {
//		if(find(v.begin(),v.end(),root)==v.end())
//			v.push_back(root);
//		v.push_back(root->left);
//	}
//	if (root->right&&root->val > root->right->val) {
//		if (find(v.begin(), v.end(), root) == v.end())
//			v.push_back(root);
//		v.push_back(root->right);
//	}
//	if (isLeft&&root->val > head->val || !isLeft&&root->val < head->val) {
//		if (find(v.begin(), v.end(), root) == v.end()) v.push_back(root);
//		if (find(v.begin(), v.end(), head) == v.end()) v.push_back(head);
//	}
//	searchWrong(root->left,isLeft,level+1);
//	searchWrong(root->right,isLeft, level + 1);
//}
//
//
//void recoverTree(TreeNode* root) {
//	if (!root) return;
//	if (root->left&&root->val < root->left->val) {
//			v.push_back(root);
//		v.push_back(root->left);
//	}
//	if (root->right&&root->val > root->right->val) {
//		if (find(v.begin(), v.end(), root) == v.end())
//			v.push_back(root);
//		v.push_back(root->right);
//	}
//	searchWrong(root->left,root,true,2);
//	searchWrong(root->right,root, false,2);
//	for (int i = 0; i < v.size(); i++)
//		for (int j = i + 1; j < v.size(); j++) {
//			swap(v[i]->val, v[j]->val);
//			if (isValid(v[i]) && isValid(v[j])) { cout << v[i]->val << endl << v[j]->val; return; }
//			else swap(v[i]->val, v[j]->val);
//		}
//}
TreeNode* buildTree(vector<int> &v, int n) {
	TreeNode* root;
	if (n > v.size() || v[n - 1] == NULL) return NULL;
	root = new TreeNode(v[n - 1]);
	root->left = buildTree(v, 2 * n);
	root->right = buildTree(v, 2 * n + 1);
	return root;
}

void morrisTraversal(TreeNode* root) {
	TreeNode* temp = NULL;
	while (root != NULL) {
		if (root->left != NULL) {
			// connect threading for root
			temp = root->left;
			while (temp->right != NULL && temp->right != root)
				temp = temp->right;
			// the threading already exists
			if (temp->right != NULL) {
				temp->right = NULL;
				cout << root->val << endl;
				root = root->right;
			}
			else {
				// construct the threading
				temp->right = root;
				root = root->left;
			}
		}
		else {
			cout << root->val << endl;
			root = root->right;
		}
	}
}

int main() {
	//TreeNode* head = buildTree(vector<int> {146, 71, -13, 55, NULL, 231, 399, 321, NULL, NULL, NULL, NULL, NULL, -33}, 1);
	//recoverTree(head);
	TreeNode* head = buildTree(vector<int> {4,2,6,1,3, 5, 7}, 1);
	morrisTraversal(head);
	return 1;

}