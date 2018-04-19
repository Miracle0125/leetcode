

#include"common.h"
using namespace std;

//me
ListNode* removeElements(ListNode* head, int val) {
	while (head&&head->val == val)
		head = head->next;
	if (head) 
		head->next = removeElements(head->next, val);
	return head;
}


ListNode* removeElements2(ListNode* head, int val) {
	if (!head) return head;
	head->next = removeElements2(head->next, val);
	return head->val == val ? head->next : head;
}

//ListNode* removeElements(ListNode* head, int val) {
//	//recurse(head,val);
//	if (head) {
//		if(head->val == val) {
//			if(head->next)
//				head->next= removeElements(head->next->next, val);
//			else return head->next;
//		}
//		head->next = removeElements(head->next, val);
//	}
//	return head;
//}