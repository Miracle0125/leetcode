
#include<vector>
#include"common.h"
using namespace std;



 TreeNode* toBST(ListNode* head, ListNode* tail) {
	ListNode* slow = head;
	ListNode* fast = head;
	if (head == tail) return NULL;

	//fast 到尾的时候slow 刚到中间,相当于(l+r)/2
	while (fast != tail&&fast->next != tail) {
		fast = fast->next->next;
		slow = slow->next;
	}
	TreeNode* thead = new TreeNode(slow->val);
	thead->left = toBST(head, slow);
	thead->right = toBST(slow->next, tail);
	return thead;
}

 //better
 TreeNode* sortedListToBST2(ListNode* head) {
	 if (head == NULL) return NULL;
	 return toBST(head, NULL);
 }

//me 转化成108
TreeNode* sortedListToBST(vector<int>& nums, TreeNode* root, int l, int r) {
	if (l != r) {
		int mid = (r + l) / 2;
		root = new TreeNode(nums[mid]);
		if (l != mid)
			root->left = sortedListToBST(nums, root, l, mid - 1);
		root->right = sortedListToBST(nums, root, mid + 1, r);
		return root;
	}
	else return new TreeNode(nums[l]);
}

TreeNode* sortedListToBST(ListNode* head) {
	if (!head) return NULL;
	vector<int> nums;
	while (head) {
		nums.push_back(head->val);
		head = head->next;
	}
	return  sortedListToBST(nums,NULL,0,nums.size()-1);
}


//TreeNode* sortedListToBST(ListNode* head, ListNode* tail,int l,int r) {
//	if (l != r) {
//		ListNode*  pre = head;
//		TreeNode* root;
//		int mid = (r + l) / 2;
//		for (int i = 0; i < mid - 1; i++)
//			pre = pre->next;
//		root = new TreeNode(pre->next->val);
//		root->left = sortedListToBST(head, pre, l, mid - 1);
//		root->right = sortedListToBST(pre->next->next, tail, mid+1, r);
//		return root;
//	} else return new TreeNode(head->val);
//
//	
//}

//TreeNode* sortedListToBST(ListNode* head) {
//	if (!head) return NULL;
//	ListNode* tail = head;
//	int len = 1;
//	while (tail->next) {
//		tail = tail->next;
//		len++;
//	}
//	return  sortedListToBST(head, tail,0,len-1);
//}


