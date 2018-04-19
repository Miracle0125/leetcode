
#include"common.h"
using namespace std;

//����ݹ飬�Һ����⣬д����ˬ��
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