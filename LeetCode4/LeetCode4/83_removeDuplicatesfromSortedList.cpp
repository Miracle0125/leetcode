
#include"common.h"
using namespace std;



//better ,using recursion,    �����̫���ˣ�
//��β����ʼ�ݹ�
ListNode* deleteDuplicates_83(ListNode* head) {
	if (!head || !head->next) return head;
	head->next = deleteDuplicates_83(head->next);
	return head->val == head->next->val ? head->next : head;
}

//me
	ListNode* deleteDuplicates2(ListNode* head) {
		if (head) {
			ListNode* p =head;
			int num = p->val;
			while (p->next) {
				if (p->next->val == num) {
					p->next = p->next->next ? p->next->next : NULL;
					continue;
				}
				p = p->next;
				num = p->val;
			}
		}
		return head;
	}