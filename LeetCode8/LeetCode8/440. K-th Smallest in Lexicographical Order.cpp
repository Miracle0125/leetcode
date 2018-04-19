


#include"common.h"

int weight[11] = { 0,1,11,111,1111,11111,111111,1111111,11111111,111111111,1111111111 };
int search(int w,int index,int num,bool is_uncomplete) {
	//num = num * 10 + index / weight[w];
	if (w == 1) return num * 10 + index;
	int index_left = index%weight[w];
	if(!index_left)
	return search(w - 1, index%weight[w], num * 10 + index / weight[w], is_uncomplete);
}


int findKthNumber(int n, int k) {
	if (n < 10) return k;
	int bits=0;
	for (int temp = n; temp != 0; temp /= 10, bits++);
	return search(bits - 1, k%weight[bits], k / weight[bits] + 1, true);
}


int main() {
	auto r = findKthNumber(3456,300);
	return 1;
}