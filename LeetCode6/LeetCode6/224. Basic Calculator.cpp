
#include<string>
#include<stack>
using namespace std;


int calculateI(string s) {
	stack<int> cache;
	int sign = 1, ret = 0, num = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 48) {
			num = num * 10 + (s[i] - 48);
		}else if(s[i]>='+'){
			ret += num*sign;
			sign = s[i] == '+' ? 1 : -1;
			num = 0;
		}else if(s[i]>=40){
			if (s[i] == 40) {
				cache.push(ret);
				cache.push(sign);
				ret = 0;
				sign = 1;
			}else{
				ret += sign*num;
				num = 0;
				ret *= cache.top();
				cache.pop();
				ret += cache.top();
				cache.pop();
				
			}
		}
	}
	if (num) { ret += sign*num; }
	return ret;
}


//int main() {
//int ret=	calculate("(5-(1+(5)))");
//	return 0;
//}


//int getTotalNumber(string&s,int& i,bool left_to_right) {
//	int ret = 0;
//	if (left_to_right) {
//		for (; i < s.size(), s[i] >= 48; i++) 
//			ret = ret * 10 + (s[i] - 48);
//		i--;
//	}else{
//		for (int power = 1; i < s.size(), s[i] >= 48; i--, power *= 10)
//			ret += power*(s[i] - 48);
//		i++;
//	}
//	return ret;
//}
//
//int calculate(string s) {
//	int ret = 0, sign = 1, l = 0, r = s.size() - 1;
//		for (; l <=r; l++)
//		{
//			if (s[l] >= 48) {
//				int num = getTotalNumber(s, l, true);
//				ret += sign*num;
//			}else {
//				if (s[l] == ' ') continue;
//				if (s[l] == '+') sign = 1;
//				else if (s[l] == '-') sign = -1;
//				else break;//(
//			}
//		}
//		for (; l <= r; r--)
//		{
//			if (s[r] >= 48) {
//				int num = getTotalNumber(s, r, false);
//				int sign = 1;
//				for (r--; ; r--)
//				{
//					if (s[r] != ' ') {
//						if (s[r] != '+') 
//							sign = -1;
//						break;
//					}
//				}
//				ret += sign*num;
//			}
//			else {
//				if (s[r] != ' ') {
//					ret += sign*calculate(s.substr(l + 1, r - l - 1));
//					break;
//				}
//			}
//		}
//	return ret;
//}
