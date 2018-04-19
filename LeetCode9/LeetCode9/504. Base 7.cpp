

#include"common.h"



string convertToBase7(int num) {
	if (!num) return "0";
	string s;
	bool neg = num < 0;
	num = abs(num);
	while (num) {
		s.push_back(num % 7 + '0');
		num /= 7;
	}
	if (neg) s.push_back('-');
	reverse(s.begin(), s.end());
	return s;
}