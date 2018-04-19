#include<vector>
#include<iostream>
#include<map>
#include<algorithm>
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
vector<string> split(string s, char c);
string itoa(int i);
int atoi(string s);
TreeNode* deserialize(string s);
//static int binarySearch(vector<int> &a, int fromIndex, int toIndex,
//	int key);

// vector<vector<string>> partition(string s);