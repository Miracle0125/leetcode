
#include"common.h"
using namespace std;




	ListNode* reverseLinkedList(ListNode* head) {
		if (head && head->next) {
			ListNode* median = head->next, *last = median->next;
			head->next = NULL;
			while (median) {
				median->next = head;
				head = median;
				median = last;
				if (last) last = last->next;
			}
		} 
	return head;
}

bool isPalindrome(ListNode* head) {
		int len = 0;
		ListNode* tail = head,*l2,*l1;
		for (; tail; len++, tail = tail->next);
		if (len <= 1) return true;
		tail = head;
		for (int i = 0; i < len/2-1; i++)
			tail = tail->next;
		l2 = tail->next;
		if (len & 1)l2 = l2->next;
		tail->next = NULL;
		l1 = reverseLinkedList(head);
		while (l1) {
			if (l1->val != l2->val)return false;
			l1 = l1->next;
			l2 = l2->next;
		}
		return true;
}







//»áÒç³ö
//bool isPalindrome(ListNode* head) {
//	if (!head) return false;
//	int len = 0,sum=0,half=0;
//	ListNode* tail = head;
//	while (tail) {
//		sum += tail->val;
//		len++;
//		tail = tail->next;
//	}
//	for (int i = 0; i < len/2; i++)
//	{
//		half += head->val;
//		head = head->next;
//	}
//	if (len | 0) sum -=head->val;
//	return half == sum/2;
//}