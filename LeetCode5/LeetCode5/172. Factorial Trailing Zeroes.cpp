#include<string>
#include<iostream>
#include<vector>
using namespace std;


//�۲�׳����������ÿ������5��10��15��5�ı���ʱ0��+1����25=5*5��0��+2���Դ�����125+3
int trailingZeroes(int n) {
	return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
}
