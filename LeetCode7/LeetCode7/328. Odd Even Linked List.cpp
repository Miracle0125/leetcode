

using namespace std;
#include"common.h"


//Ò»·¢Èë»ê£¬one pass ,beats 92.3%  :D
ListNode* oddEvenList(ListNode* head) {
	if (head) {
		auto odd = head->next, p = head, q = p;
		int len = 1;
		for (; p&&p->next;	len++) {
			q = p->next;
			p->next = p->next->next;
			swap(p, q);
		}
		if (len & 1)p->next = odd;
		else q->next = odd;
	}
	return head;
}