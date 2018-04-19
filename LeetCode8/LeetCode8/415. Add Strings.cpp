

#include"common.h"



string addStrings(string num1, string num2) {
	int bound = max(num1.size(), num2.size()), carry=0, p1 = num1.size() - 1, p2 = num2.size() - 1;
	string ret;
	for (int i = 0; i < bound; i++, p1--, p2--)
	{
		char a = p1 < 0 ? '0' : num1[p1], b = p2 < 0 ? '0' : num2[p2];
		char cur = a + b + carry - '0';
		if (cur > '9') { 
			cur -= 10;
			carry = 1;
		}
		else carry = 0; 
		ret.insert(ret.begin(), cur);
	}
	if (carry) ret.insert(ret.begin(), '1');
	return ret;
}