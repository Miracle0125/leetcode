#include"common.h"
using namespace std;


//��A��B�ھ����յ�ͬ���ĵط�����
//д�������������������
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