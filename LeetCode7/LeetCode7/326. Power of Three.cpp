




#include"common.h"
#include<set>
using namespace std;
//µ÷Æ¤Ò»ÏÂ:)
bool isPowerOfThree(int n) {
	set<int> v = { 
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
	return v.find(n)==v.end() ? false : true;	
}
bool isPowerOfThree2(int n) {
	return (n > 0 && 1162261467 % n == 0);
}