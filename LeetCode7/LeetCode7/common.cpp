#include<vector>
#include<iostream>
#include"common.h"
#include<sstream>
#include<algorithm>
using namespace std;


void printMatrix(vector<int> &v) {
	for (int i : v) {
		cout << i << " ";
	}
	cout << endl;
}

ListNode* buildLinkedList(vector<int>& v) {
	ListNode* cache = NULL, *p, *head = NULL;
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

vector<string> split(string s,char c) {
	vector<string> ret{}; 
	if (s.size() > 0) {
		s.push_back(c);
		for (int i = 0, begin = 0; i < s.size(); i++)
		{
			if (s[i] == c) { ret.push_back(s.substr(begin, i - begin)); begin = i + 1; }
		}
	}
	return ret;
}

/** n=1*/
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

void printMatrix(vector<vector<int>> &v) {
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			cout << v[i][j] << " ";
			if (!(v[i][j] / 10)) cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}


void printMatrix_str(vector<vector<string>> &v) {
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			for (auto&& k:v[i][j])
			{
				cout << k;
			}
			cout << " ";
			//cout << v[i][j] << " ";
			//if (!(v[i][j] / 10)) cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int atoi(string s) {
	istringstream ist(s);
	int ret;
	ist >> ret;
	return ret;
}
string itoa(int i) {
	stringstream ss;
	ss << i;
	return ss.str();
}

//void printMatrix(vector<vector<string>> &v) {
//	for (int i = 0; i < v.size(); i++)
//	{
//		for (vector<string>::iterator j = v[i].begin(); j != v[i].end(); j++)
//		{
//			cout << *j << " ";
//			//if (!(v[i][j] / 10)) cout << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//}
TreeNode* deserialize(string s) {
	TreeNode* root = nullptr;
	vector<string> v = split(s.substr(1, s.size() - 2), ',');
	if (!v.empty()) {
		root = new TreeNode(atoi(v[0]));
		vector<TreeNode*> temp{ root }, vec;
		int cap = 3, i = 1, inc = 0;
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

//static int binarySearch(vector<int> &a, int fromIndex, int toIndex,
//	int key) {
//	int low = fromIndex;
//	int high = toIndex - 1;
//
//	while (low <= high) {
//		int mid = (low + high) >> 1;
//		int midVal = a[mid];
//
//		if (midVal < key)
//			low = mid + 1;
//		else if (midVal > key)
//			high = mid - 1;
//		else
//			return mid; // key found
//	}
//	return -(low + 1);  // key not found.
//}

