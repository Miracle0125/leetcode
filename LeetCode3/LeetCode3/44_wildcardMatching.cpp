#include<string>
using namespace std;



/*
	����ע�������������粻����ȫƥ�䣬��j���ص�*���棬i����������Ĵ��룡
	�������java�汾���߲�ʹ��ָ�룬��Ҫ���븴�ӵı߽��ж�
*/
bool isMatch(string s, string p) {
	char* i = &s[0], *j = &p[0], *star = NULL, *ss=i;
	int n = s.length(),m = p.length();
	while (*i)
	{
		if (*i == *j || *j == '?') { i++; j++; continue; }
		if (*j == '*') { star = j++; ss = i; continue; }
		if (star) { j = star + 1; i = ++ss; continue; }//!!j=star+1   ����֮�ʣ�
		return false;
		//a......ab..abc
		//a*abc
	}
	//if (j == m) { 
	//	if (p[m - 1] == '*'||i==n) return true; 
	//	else return false;
	//}
	while(*j == '*') j++;
	return !*j;
}


//int main() {
//	//isMatch("a......ab..abc", "a*abc");
//	isMatch("aa", "*");
//	system("pause");
//}