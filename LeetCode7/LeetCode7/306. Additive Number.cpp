

using namespace std;
#include"common.h"

//
//
//bool isAdditiveNumber(string num) {
//	for (int i = 1; i <= num.size() / 2; i++) {
//		for (int j = 1; j <= (num.size() - i) / 2; j++) {
//			if (check(num.substr(0, i), num.substr(i, j), num.substr(i + j))) return true;
//		}
//	}
//	return false;
//}
//bool check(string num1, string num2, string num) {
//	if (num1.size()>1 && num1[0] == '0' || num2.size()>1 && num2[0] == '0') return false;
//	string sum = add(num1, num2);
//	if (num == sum) return true;
//	if (num.size() <= sum.size() || sum.compare(num.substr(0, sum.size())) != 0) return false;
//	else return check(num2, sum, num.substr(sum.size()));
//}
//string add(string n, string m) {
//	string res;
//	int i = n.size() - 1, j = m.size() - 1, carry = 0;
//	while (i >= 0 || j >= 0) {
//		int sum = carry + (i >= 0 ? (n[i--] - '0') : 0) + (j >= 0 ? (m[j--] - '0') : 0);
//		res.push_back(sum % 10 + '0');
//		carry = sum / 10;
//	}
//	if (carry) res.push_back(carry + '0');
//	reverse(res.begin(), res.end());
//	return res;
//}
//
//
//leetcode的编译器和我的是不是不一样啊 ？  本地跑的通的代码在上面跑不通
//string s;
//int len;
//bool isAdditiveNumber(int a, int b, int i, int n) {
//	if (n == 1) {
//		return a + b == atoi(s.substr(i, len));
//	}else{
//		for (int j = i, limit0 = s[i] == '0' ? 1 : len - (n - 1); j < limit0; j++) {
//			if (isAdditiveNumber(b, atoi(s.substr(i, j - i + 1)), j + 1, n - 1)) return true;
//		}
//		return false;
//	}
//}
//
//bool isAdditiveNumber(string num) {
//	s = num;
//	len = s.size();
//	for (int n = 1; n <= len - 2; n++) {
//		for (int i = 0, limit0 = s[0] == '0' ? 1 : len - (n - 1); i < limit0; i++)
//		{
//			for (int j = i + 1, limit1 = s[i + 1] == '0' ? i + 2 : len - n; j < limit1; j++)
//			{
//				
//				if (isAdditiveNumber(atoi(s.substr(0, i + 1)), atoi(s.substr(i + 1, j - i)), j + 1, n)) return true;
//			}
//		}
//	}
//	return false;
//}




