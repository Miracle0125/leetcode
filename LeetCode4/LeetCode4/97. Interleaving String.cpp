#include<vector>
#include<string>
#include<iostream>
#include"common.h"
using namespace std;

//��զ���벻������DP�ⷨ�أ����� ��ʵ��wild match ����
//һ����ά����1��0��ɵ�bool����ԭ�㣨0��0��Ϊ1��ĳһ��ҪΪһ����Ҫ�»���Ϊ1������һ�������������������쵽�յ�
//�ǳ������Ľⷨ
bool isInterleave2(string s1, string s2, string s3) {
	if (s3.length() != s1.length() + s2.length())
		return false;
	vector<vector<bool>> table(s1.length()+ 1, vector<bool>(s2.length()+1,false));
	for (int i = 0; i<s1.length() + 1; i++)
		for (int j = 0; j< s2.length() + 1; j++) {
			if (i == 0 && j == 0)
				table[i][j] = true;
			else if (i == 0)
				table[i][j] = (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
			else if (j == 0)
				table[i][j] = (table[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
			else
				table[i][j] = (table[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
		}

	return table[s1.length()][s2.length()];
}

//����������˲�ͬ��DP�ⷨ�������Ͻ��ٶȲ�࣡
string a, b,c;
void isInterleave(int i, int j, int k,int type, vector<vector<int>>& map) {
	if (map[i][j]||!type? a[i]!=c[k]:b[j]!=c[k]) return;
	map[i][j] = 1;
	if (i) isInterleave(i - 1, j, k - 1, 0, map);
	if (j) isInterleave(i, j - 1, k - 1, 1, map);
}

bool isInterleave(string s1, string s2, string s3) {
	a = s1, b = s2,c=s3;
	int m=s1.length(),n=s2.length(),size = s3.length();
	if (m + n != size) return false;
	if (m == 0&&n == 0) return true;
	vector<vector<int>> map(m+1, vector<int>(n+1, 0));
	if(m) isInterleave(m - 1, n, size - 1, 0, map);
	if(n) isInterleave(m, n - 1, size - 1, 1, map);
	return map[0][0];
}

//int main() {
//	//string s1 = "aabcc";
//	//	string	s2 = "dbbca";
//	//	string  s3 = "aadbbcbcac";		bool b = isInterleave(s1, s2, s3);
//
//		return b;
//}