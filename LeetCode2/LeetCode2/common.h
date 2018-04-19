struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *n) : val(x), next(n) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);