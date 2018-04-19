
#include<string>
#include<stack>
using namespace std;

#define calc(sign,a,b) (sign=='*'?a*b:a/b)
int calculate(string s) {
	//sign: add or minus;  sign2: multiply or divide ;
	int sign = 1, sign2 = 0, ret = 0, num = 0, left_side = 0;
	s.push_back('+');
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 48) {
			num = num * 10 + (s[i] - 48);
		}
		else if (s[i] == '+' || s[i] == '-') {
			if (sign2)
				ret+=sign*calc(sign2, left_side, num);
			else ret += num*sign;
			sign = s[i] == '+' ? 1 : -1;
			num = sign2 = 0;
		}else if(s[i]>='*'){
			if (sign2) 
				left_side = calc(sign2, left_side, num);
			else left_side = num;
			num = 0;
			sign2 = s[i];
		}
	}
	return ret;
}