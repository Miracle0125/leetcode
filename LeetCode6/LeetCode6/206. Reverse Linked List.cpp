
#include"common.h"
using namespace std;

//这个递归，我很满意，写的真爽！
ListNode* tail;
ListNode* recurse(ListNode* head) {
	if (head) {
		ListNode* follow = recurse(head->next);
		if (follow) follow->next = head;
		else tail = head;
	}
	return head;
}

ListNode* reverseList(ListNode* head) {
	if (head) {
		recurse(head);
		head->next = NULL;
	}
	return tail;
}