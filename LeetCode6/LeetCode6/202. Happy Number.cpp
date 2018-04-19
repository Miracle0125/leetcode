
#include<iostream>
using namespace std;
//检测链表是否有环......
//技不如人，甘拜下风.......

int add_square(int n) {
	int ret = 0;
	while (n != 0) {
		int i = n % 10;
		ret += i*i;
		n /= 10;
	}
	return ret;
}

bool isHappy(int n) {
	int fast,slow;
	fast = slow = n;
	do {
		fast = add_square(add_square(fast));
		slow = add_square(slow);
		cout << fast << " " << slow << endl;
	} while (fast!=slow);
	return fast == 1 ? true : false;
}