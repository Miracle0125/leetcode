
#include"common.h"

void reorderList(ListNode* head) {
	if (!head||!head->next) return;
	ListNode* fast = head, *slow = head,*pre=NULL,*tail=NULL,*p=head,*temp=NULL;
	while (fast&&fast->next) {
		pre = slow;
		fast = fast->next->next;
		slow = slow->next;
	}
	tail = slow;
	p = slow->next;
	while (p) {
		pre->next = p;
		p = pre->next->next;
		pre->next->next = slow;
		slow = pre->next;
	}
	if(tail)tail->next = NULL;
	fast = pre->next;
	pre->next = NULL;
	slow = head;
	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	p = dummy;
	bool mark = true;
	printLinkedList(head);
	while (fast) {
		if (mark&&slow) {
			p->next = slow;
			slow = slow->next;
		}
		else {
			p->next = fast;
			fast = fast->next;
		}
		p = p->next;
		mark = !mark;
	}
	dummy->next = NULL;
}

//int main() {
//	ListNode* head = buildLinkedList(vector<int>{1, 2, 3, 4,5});
//	reorderList(head);
//	return 1;
//}