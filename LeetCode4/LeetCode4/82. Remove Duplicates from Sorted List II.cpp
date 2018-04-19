#include"common.h"


class s82 {
private:
	int n = INT_MIN;

	ListNode* deleteDuplicates(ListNode* head) {
		if (!head) return head;
		head->next = deleteDuplicates(head->next);
		if (head->val == n) {
			if (!head->next) return NULL;
			return head->next->val == head->val ? head->next->next : head->next;
		}
		else {
			n = head->val;
			return head;
		}
	}

};
//我能写出这么简洁的代码真是能吹一年


