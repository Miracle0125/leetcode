#include<string>
using namespace std;


int lengthOfLastWord(string s) {
	int l = 0;
	for (int i = s.length()-1; i >= 0; i--)
		if (s[i] != ' ') l++;
		else if(l) break;
	return l;
}