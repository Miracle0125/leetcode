#include<vector>
#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

int numIslands(vector<vector<char>> A);
bool isHappy(int n);
ListNode* reverseList(ListNode* head);
ListNode* removeElements(ListNode* head, int val);
int rangeBitwiseAnd(int m, int n);
int minSubArrayLen(int s, vector<int>& A);
bool isPalindrome(ListNode* head);

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

// vector<vector<string>> partition(string s);