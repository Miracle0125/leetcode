#include"common.h"
#include<algorithm>
using namespace std;

void deleteNode(ListNode* node) {
	*node = *node->next;
}