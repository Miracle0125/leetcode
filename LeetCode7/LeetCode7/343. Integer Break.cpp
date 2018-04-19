



using namespace std;
#include<set>
#include"common.h"

int integerBreak(int n) {
	vector<int> v = {
		1,
		3,
		9,
		27,
		81,
		243,
		729,
		2187,
		6561,
		19683,
		59049,
		177147,
		531441,
		1594323,
		4782969,
		14348907,
		43046721,
		129140163,
		387420489,
		1162261467 };
	if (n == 2) return 1;
	if (n == 3) return 2;
	int left = n % 3, i = n / 3;
	if (left <= 1) { left += 3; i--; }
	return v[i] * left;
}