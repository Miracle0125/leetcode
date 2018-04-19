#include<string>
#include<iostream>
#include<vector>
using namespace std;


//观察阶乘输出，发现每当乘以5、10、15等5的倍数时0数+1，又25=5*5，0数+2，以此类推125+3
int trailingZeroes(int n) {
	return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
}
