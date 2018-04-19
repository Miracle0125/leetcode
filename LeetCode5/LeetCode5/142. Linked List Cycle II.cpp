// i cann.t understand

#include"common.h"
ListNode *detectCycle(ListNode *head) {
	ListNode* fast = head, *slow = head;
	bool hasCycle = false;
	while (fast&&fast->next) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow) { hasCycle = true; break; }
	}
	slow = head;
	if (!hasCycle) return NULL;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

