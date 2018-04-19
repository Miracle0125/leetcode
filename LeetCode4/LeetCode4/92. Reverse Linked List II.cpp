#include<vector>
#include"common.h"
using namespace std;





//�ҵ��뷨��ʵ�е������ˣ������������Ҫ������һ��   .  Ĭд�汾
ListNode* reverseBetween(ListNode* head, int m, int n) {
	if (!head) return head;
	ListNode* dummy = new ListNode(0), *p1, *p2;
	dummy->next = head;
	ListNode* pre = dummy;
	for (int i = 0; i < m-1; i++)
		pre = pre->next;
	p1 = pre->next;
	p2 = p1->next;
	for (int i = 0; i < n-m; i++)
	{
		p1->next = p2->next;
		p2->next = pre->next;
		pre->next = p2;
		p2 = p1->next;
	}
	return dummy->next;
}




//�ݸ�  ����Ҫ��one pass��  ��������....
ListNode* reverseBetween2(ListNode* head, int m, int n) {
	if (!head||!head->next||m==n) return head;
	ListNode* p1=head, *p2, *p3;
	int len = 1;
	while (head->next) {
		head = head->next;
		len++;
	}
	//������
	head->next = p1;
	for (int i = 0; i < m-1; i++)
		head = head->next;
	p1 = head;
	p2 = head->next;
	p3 = p2->next;
	for (int i = 0; i < n-m+1; i++)
		head = head->next;
	p1->next = head;
	for (int i = 0; i < n-m; i++)
	{
		p2->next = p1;
		p1 = p2;
		p2 = p3;
		if(p3)
		p3 = p3->next;
	}
	for (int i = 0; i < len-n; i++)
	{
		p1 = p1->next;
	}
	head = p1->next;
	p1->next = NULL;
	return head;
}