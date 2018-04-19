#include<queue>
#include<vector>
#include<iostream>
#include"common.h"
using namespace std;

//ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//	if (l1 == NULL) return l2;
//	if (l2 == NULL) return l1;
//
//	if (l1->val < l2->val) {
//		l1->next = mergeTwoLists(l1->next, l2);
//		return l1;
//	}
//	else {
//		l2->next = mergeTwoLists(l2->next, l1);
//		return l2;
//	}
//}

ListNode* mergeKLists(vector<ListNode*>& lists) {
	int n = lists.size();
	if (n == 0) return nullptr;
	if (n == 1) return lists[0];
	if (n == 2) return mergeTwoLists(lists[0], lists[1]);
	vector<ListNode*> v1,v2;
	v1.assign(lists.begin(), lists.begin() + n / 2);
	v2.assign(lists.begin() + n / 2, lists.end());
	//priority_queue<ListNode*, vector<ListNode*>, cmp >p;
	return mergeTwoLists(mergeKLists(v1),mergeKLists(v2));
}


//int main() {
//	 //ListNode* p = &ListNode(-3,&ListNode(-2,&ListNode(1)));
//	 //vector<ListNode*> v{ nullptr, &ListNode(-2), p };
//	 //p= mergeKLists(v);
//	system("pause");
//	return 0;
//}