#include<vector>
#include<iostream>
#include"common.h"
#include<string>
using namespace std;


void output_impl(TreeNode* n, bool left, string const& indent)
{
	if (n->right)
	{
		output_impl(n->right, false, indent + (left ? "|     " : "      "));
	}
	cout << indent;
	cout << (left ? '\\' : '/');
	cout << "-----";
	cout << n->val << endl;
	if (n->left)
	{
		output_impl(n->left, true, indent + (left ? "      " : "|     "));
	}
}

void output(TreeNode* root)
{
	if (root->right)
	{
		output_impl(root->right, false, "");
	}
	cout << root->val << endl;
	if (root->left)
	{
		output_impl(root->left, true, "");
	}
}

void printMatrix(vector<int> &v) {
	for (int i : v) {
		cout << i << " ";
	}
	cout << endl;
}

ListNode* create(vector<int>& v) {
	ListNode* cache=NULL, *p,*head=NULL;
	for (int i = 0; i < v.size(); i++)
	{
		p = new ListNode(v[i]);
		if (cache) cache->next = p;
		else head = p;
		cache = p;
	}
	return head;
}

void printLinkedList(ListNode* head) {
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}


TreeNode* buildTree(vector<int> &v, int n) {
	TreeNode* root;
	if (n > v.size() || v[n - 1] == NULL) return NULL;
	root = new TreeNode(v[n - 1]);
	root->left = buildTree(v, 2 * n);
	root->right = buildTree(v, 2 * n + 1);
	return root;
}



//TreeNode* buildTree(vector<int> &v) {
//	TreeNode* p;
//	
//}

//void printMatrix(vector<vector<int>> &v) {
//	for (int i = 0; i < v.size(); i++)
//	{
//		for (int j = 0; j < v[0].size(); j++)
//		{
//			cout << v[i][j] << " ";
//			if (!(v[i][j] / 10)) cout << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//}
