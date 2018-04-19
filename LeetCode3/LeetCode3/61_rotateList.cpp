#include"common.h"
#include<iostream>

using namespace std;


void buildLinkedList(ListNode* head,vector<int>&v) {
	head = &ListNode(v[0]);
	ListNode/** head = &ListNode(v[0]),*/*p=head;
	for (int i = 0; i < v.size()-1; i++)
	{
		p->next = &ListNode(v[i + 1]);
		p = p->next;
	}
	//return head;
}

void printLinkedList(ListNode* head) {
	cout << head->val << " ";
	while (head->next)
		head = head->next;
	cout << endl;
}
//better
ListNode* rotateRight2(ListNode* head, int k) {
	if (!head) return head;

	int len = 1; // number of nodes
	ListNode *newH, *tail;
	newH = tail = head;

	while (tail->next)  // get the number of nodes in the list
	{
		tail = tail->next;
		len++;
	}
	tail->next = head; // circle the link

	if (k %= len)
	{
		for (auto i = 0; i<len - k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
	}
	newH = tail->next;
	tail->next = NULL;
	return newH;
}

// 1 2 3  4 5   k =2 
//��K�Ķ����е����� ԭ���Ǵ�ĩβ���� ��(len-k)����

ListNode* rotateRight(ListNode* head, int k) {
	if (head == NULL||k==0) return head;
	// for 1 2 3 4 5    and 2   pivot is 3
	ListNode* cache = head,*pivot;
	int c = 0;
	for (int i = 0; i < k; i++) {
		if (head->next) {
			head = head->next;
			c++;
		}
	}
	if (c < k) return cache;  // ��� k�ǲ�����ĩβ
	pivot = head;
	while (head->next)
		head = head->next;    //head  ָ��ĩ��
	head->next = cache;    //���ɻ�
	head = pivot->next;
	pivot->next = NULL;
	return head;
}


//int main() {
//	ListNode* head=&ListNode(1);
//	rotateRight(head,1);
//	buildLinkedList(head,vector<int>{1,2,3,4,5,6,7,8,9});
//	printLinkedList(head);
//	system("pause");
//}