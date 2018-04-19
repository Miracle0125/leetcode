#include<vector>
using namespace std;

//beter
bool isScramble(string s1, string s2) {
	if (s1 == s2)
		return true;

	int len = s1.length();
	int count[26] = { 0 };
	for (int i = 0; i<len; i++)
	{
		count[s1[i] - 'a']++;
		count[s2[i] - 'a']--;
	}

	for (int i = 0; i<26; i++)
	{
		if (count[i] != 0)
			return false;
	}

	for (int i = 1; i <= len - 1; i++)
	{
		if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
			return true;
		if (isScramble(s1.substr(0, i), s2.substr(len - i)) && isScramble(s1.substr(i), s2.substr(0, len - i)))
			return true;
	}
	return false;
}


//bool isScramble(string s1,string s2){
//	if (s1.length() != s2.length()) return false;
//	if (s1 == s2) return true;
//	int div = s1.length() / 2;
//	string s10 = s1.substr(0, div),s11=s1.substr(div,s1.length());
//	string s20 = s2.substr(0, div), s21 = s2.substr(div, s2.length());
//	return isScramble(s10, s20) && isScramble(s11, s21) || isScramble(s11, s20) && isScramble(s10, s21);
//}

//bool isScramble(string s1, string s2) {
//	if (s1.length() != s2.length()) return false;
//	return check(s1, s2);
//}


//int main() {
//bool b=	isScramble("rgeat", "great");
//return 1;
//}