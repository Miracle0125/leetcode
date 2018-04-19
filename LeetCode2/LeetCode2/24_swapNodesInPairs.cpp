#include<iostream>
#include<string>
#include"common.h"
using namespace std;

 ListNode* swapPairs(ListNode* head) {
	 ListNode **pp = &head, *a, *b;
	 while ((a = *pp) && (b = a->next)) {
		 a->next = b->next;
 		 b->next = a;
		 *pp = b;
		 pp = &(a->next);
	 }
	 return head;
 }

 //int main() {
	// struct ListNode n4 = { 4 };
	// struct ListNode n3 = { 3 ,&n4};
	// struct ListNode n2 = {2,&n3};
	// struct ListNode n1 = {1,&n2};
	//// ListNode *p = &n2,*p1;
	// //string s = (p1 = p->next) ? "true" : "false";
	//// cout << s;
	//ListNode* p =  swapPairs(&n1);
	//do {
	//	cout << p->val << " ";
	//	p = p->next;
	//} while (p!=nullptr);
	// system("pause");
 //}