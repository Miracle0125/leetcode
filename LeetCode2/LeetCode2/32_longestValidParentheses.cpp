#include<iostream>
#include<vector>
using namespace std;



int longestValidParentheses(string s) {
	if (s.length() == 0) return 0;
	int l = 0, count = 1,len = 0,j;
	for (int i = 0; i < s.length()-1; i++)
	{
		if (s[i] == '(') {
			count = 1;
			for (j = 1; i + j < s.length(); j++)
			{
				if (s[i + j] == '(')count++;
				else count--;
				if (count == 0) {
					if (j + 1 > len) len = j + 1;
				}
				else if (count < 0) {
					//ÊÇ·ñÃ»ÓÐÂ©¶´£¿
					i +=j;
					break;
				}
			}
		}
		//if (len > s.length()-i||len>s.length()/2) break;
	}
	return len;
}