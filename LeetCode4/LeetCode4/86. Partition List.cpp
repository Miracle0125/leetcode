#include"common.h"
using namespace std;

//�Լ�д�ģ����Ǻ�����
ListNode* p,*cache;
ListNode* partition(ListNode* head, int x) {
	if (!head) return head;
	head->next = partition(head->next, x);
	if (head->val >= x&&head->next) {
			cache = head->next->val >= x ? head : head->next;
			p = head;
			while (head->next&&head->next->val < x) {
				head = head->next;
			}
			if (p != head) {
				p->next = head->next;
				head->next = p;
				head = cache;
			}
	}
	return head;
}