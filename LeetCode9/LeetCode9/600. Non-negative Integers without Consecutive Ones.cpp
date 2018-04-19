

#include"common.h"


//这个题trick太多了


int findIntegers1(int num) {
	int f[32];
	f[0] = 1;
	f[1] = 2;
	for (int i = 2; i < 32; ++i)
		f[i] = f[i - 1] + f[i - 2];
	int ans = 0, k = 30, pre_bit = 0;
	while (k >= 0) {
		if (num&(1 << k)) {
			ans += f[k];
			if (pre_bit) return ans;
			pre_bit = 1;
		}
		else
			pre_bit = 0;
		--k;
	}
	return ans + 1;
}

int findIntegers2(int num) {
	int input_val = num;
	int base = 2;
	int count = 0;
	int a = 1;   // number of integrers without contiguous 1 with heading 0
	int b = 1;   // number of integrers without contiguous 1 with heading 1
	int ext_count = 1;
	int pre_digit = 0;
	while (input_val>0) {
		int digit = input_val % base;
		input_val = input_val / base;
		if (digit == 1) {
			if ((input_val%base)>0) {
				count = 0;
			}
			count += a;
		}
		if ((digit == 1) && (pre_digit == 1)) {
			ext_count = 0;
		}
		pre_digit = digit;
		int temp = b;
		b = a;
		a = a + temp;
	}
	return (count + ext_count);
}

int findIntegers3(int num) {
	static int fb[31] = { 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946,
		17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578 };
	if (num < 3) return num + 1;
	for (int bt = 29; bt >= 0; --bt) // bt should start from 30, but OJ accepts it from 29.
		if (num & (1 << bt)) return num & (1 << (bt - 1)) ? fb[bt] : fb[bt - 1] + findIntegers3((num & ~(1 << bt)));
}


//void mark_base_n_consecutive(vector<bool>& f, int ones, int start, int& num, int bits) {
//	if (ones >= 0) {
//		for (int i = start; i <= bits - 2 - ones; i++)
//		{
//			num &= 1 << i;
//			mark_base_n_consecutive(f, ones - 1, i + 1, num, bits);
//		}
//	}
//}
//
//void mark_consecutive(vector<bool>& f, int bits) {
//	for (int i = 2, num = 3; i <= bits; num &= 1 << i++)
//	{
//
//	}
//}
//
//int findIntegers(int num) {
//	int bits = 0;
//	for (int n = num; n; n >>= 1)bits++;
//	return 0;
//}
//vector<int> f;