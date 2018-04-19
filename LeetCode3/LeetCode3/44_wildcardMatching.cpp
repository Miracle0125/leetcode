#include<string>
using namespace std;



/*
	按照注释里的情况，假如不能完全匹配，把j返回到*后面，i不动。神奇的代码！
	如果换成java版本或者不使用指针，需要加入复杂的边界判断
*/
bool isMatch(string s, string p) {
	char* i = &s[0], *j = &p[0], *star = NULL, *ss=i;
	int n = s.length(),m = p.length();
	while (*i)
	{
		if (*i == *j || *j == '?') { i++; j++; continue; }
		if (*j == '*') { star = j++; ss = i; continue; }
		if (star) { j = star + 1; i = ++ss; continue; }//!!j=star+1   神来之笔！
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