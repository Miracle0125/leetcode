#include<iostream>
#include<string>
#include"common.h"
using namespace std;

ListNode* reverseKGroup(ListNode* head, int k) {
	if (k == 1) return head;
	ListNode* cur=head,*temp;
	int count = 0;
	while ((cur!=nullptr)&&count != k) {
		cur = cur->next;
		count++;
	}
	if (count==k)
	{
		cur = reverseKGroup(cur,k);
		while (count-- > 0) {
			temp = head->next;
			head->next = cur;
			cur = head;
			head = temp;
		}
		head = cur;
	}
	return head;
}