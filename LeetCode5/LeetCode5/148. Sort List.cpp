#include"common.h"


ListNode* merge(ListNode* l1, ListNode* l2);
ListNode* sortList(ListNode* head) {
	if (!head || !head->next) return head;
	ListNode* fast = head,*slow = head,*p=NULL;
	while (fast&&fast->next) {
		p = slow;
		fast = fast->next->next;
		slow = slow->next;
	}
	p->next = NULL;
	ListNode* l1 = sortList(head);
	ListNode* l2 = sortList(slow);

	return  merge(l1, l2);
}
//   7 9 2   6 4    1 0 3
ListNode* merge(ListNode* l1, ListNode* l2) {
	ListNode* l = new ListNode(0),*p=l;
	while (l1 && l2) {
		if (l1->val < l2->val) {
			p->next = l1;
			l1 = l1->next;
		}else{
			p->next = l2;
			l2 = l2->next;
		}
		p = p->next;
	}
	if (l1)p->next = l1;
	if (l2)p->next = l2;
	return l->next;
}