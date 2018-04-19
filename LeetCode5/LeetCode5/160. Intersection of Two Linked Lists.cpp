#include"common.h"
using namespace std;


//让A与B在距离终点同样的地方起跑
//写出这个程序的人真是天才
ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
	if (!a || !b) return NULL;
	ListNode* headA = a, *headB = b,*tail=NULL;
	while (a != b) {
		if (!a->next || !b->next) {
			ListNode* tmp = (!a->next ? a : b);
			if(tail&&tail !=tmp )
				return NULL;
			else tail = tmp;
		}
		a = a ? headB : a->next;
		b = b ? headA : b->next;
	}
	return a;
}