#include<queue>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}

};


void connect3(TreeLinkNode *root) {
	if (!root) return;
	queue<TreeLinkNode*> cache, copy;
	cache.push(root);
	TreeLinkNode* p;
	while (!cache.empty()) {
		while (!cache.empty()) {
			p = cache.front();
			cache.pop();
			if (p->left) copy.push(p->left);
			if (p->right) copy.push(p->right);
			if (!cache.empty()) p->next = cache.front();
		}
		cache = copy;
		while (!copy.empty()) {
			copy.pop();
		}
	}
}