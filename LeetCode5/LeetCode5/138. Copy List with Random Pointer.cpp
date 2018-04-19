#include<vector>
#include<unordered_map>
using namespace std;
 struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };


RandomListNode *copyRandomList(RandomListNode *head) {
	if (!head) return NULL;
	RandomListNode* cache = head, *p = new RandomListNode(0), *next = NULL,*copy;
	unordered_map<RandomListNode*, RandomListNode*> map;
	while (head) {
		next = head->next;
		copy = new RandomListNode(head->label);
		head->next = copy;
		copy->next = next;
		head = next;
	}
	p = cache;
	head = p->next->next;
	while (head) {
		next = p->next;
		p->next = head;
		next->next = head->next;
		if (p->random) p->next->random = p->random->next;
		p = head;
		head = head->next->next;
	}
	if (p->random) p->next->random = p->random->next;
	
	return cache->next;
}