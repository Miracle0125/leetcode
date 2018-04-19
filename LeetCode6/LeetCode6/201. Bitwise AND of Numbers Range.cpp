#include<bitset>
#include<algorithm>
using namespace std;

//分为两部分，第一部分不动，恒等，第二部分处于变动状态，最多只有一位为1
//左往右bit比较，第一位不同的，从那位开始后面都是变化的
//写了一个下午，脑子都想炸了，结果人家代码只要一行还跑得比我快，打击是巨大的

int rangeBitwiseAnd(int m, int n) {
	if (m == n||!m) return m;
	int largest_bit = m|n,p = INT_MAX-(INT_MAX>>1),bits=30;
	for (; largest_bit >> bits != p >> bits; bits--)
		p >>= 1;
	for (; (m & p) == (n & p); bits--)
		p >>= 1;
	int ret = m >= p&&n >= p ? (m&(INT_MAX<<bits+1)) : 0;
	if (ret) {
		int variable_bits=~(INT_MAX<<bits+1);
		m &= variable_bits;
		n &= variable_bits;
	}
	for (int i = 0,l=1,r=1;; i++,l<<=1,r=(l<<1)-1)
	{
		bool in_range0= (m >= l && m <= r), in_range1= (n >= l && n <= r);
		if (in_range0== in_range1) {
			if (in_range0) return ret+l;
		}
		else return ret;
	}
}

int rangeBitwiseAnd2(int m, int n) {
	return (n > m) ? (rangeBitwiseAnd2(m / 2, n / 2) << 1) : m;
}

//int rangeBitwiseAnd(int m, int n) {
//	int c = 0;
//	while (m != n) {
//		m >>= 1;
//		n >>= 1;
//		++c;
//	}
//	return n << c;
//}