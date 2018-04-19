#include<queue>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
	
};

//better
void connect(TreeLinkNode *root) {
	if (root == NULL) return;
	TreeLinkNode *pre = root;
	TreeLinkNode *cur = NULL;
	while (pre->left) {
		cur = pre;
		while (cur) {
			cur->left->next = cur->right;
			if (cur->next) cur->right->next = cur->next->left;
			cur = cur->next;
		}
		pre = pre->left;
	}
}

//没好好审题啊，题目给的是完美二分树，可以有更好的方法的，
void connect2(TreeLinkNode *root) {
	if (!root) return;
	queue<TreeLinkNode*> cache,copy;
	cache.push(root);
	TreeLinkNode* p;
	while (!cache.empty()) {
		while (!cache.empty()) {
			p = cache.front();
			cache.pop();
			if (p->left) copy.push(p->left);
			if (p->right) copy.push(p->right);
			if(!cache.empty()) p->next = cache.front();
		}
		cache = copy;
		while (!copy.empty()) {
			copy.pop();
		}
	}
}