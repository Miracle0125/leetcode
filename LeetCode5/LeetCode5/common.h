#include<vector>
#include<iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode * left;
	TreeNode* right;
	TreeNode(int val) :val(val), left(NULL), right(NULL) {}
};


void printMatrix(vector<int> &v);

ListNode* buildLinkedList(vector<int>& v);

void printLinkedList(ListNode* head);
void printMatrix(vector<vector<int>> &v);
void printMatrix_str(vector<vector<string>> &v);
TreeNode* buildTree(vector<int> &v, int n);


// vector<vector<string>> partition(string s);