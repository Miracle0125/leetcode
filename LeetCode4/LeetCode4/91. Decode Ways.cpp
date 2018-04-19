#include<string>
#include<vector>

using namespace std;

//For example, the String now is "123xxxx" and we know all the result from 2. 
//Because 12<26, we can make this string either"12"+"3xxxx" or 1+23xxxx 
//�������dp���룬�Ҿ�����ԭ��д�ľ�����shit
//Υ��ֱ���Ĵ��룬�ǳ���.  ��β����ʼһ�������ۣ���̫���� Ϊʲô  memo[i] = memo[i + 1] + memo[i + 2]
 int numDecodings(string s) {
		int n = s.length();
		if (n == 0) return 0;
		vector<int> memo(n + 1, 0);
		memo[n] = 1;
		memo[n - 1] = s[n - 1] != '0' ? 1 : 0;

		for (int i = n - 2; i >= 0; i--)
			if (s[i] == '0') continue;
			else memo[i] = (s[i] == '1'||s[i+1]=='2'&&s[i+1]<'6') ? memo[i + 1] + memo[i + 2] : memo[i + 1];
			return memo[0];
	}



//me  ����ṹ�ĳ����������Բ�ˬ..   ���ǲ��ɹ�
int numDecodings(string &s,int min, int n) {
	int ret = 0;
	if(n==1)
		for (int i = min; i <= s.size()-2; i++)
			if (s[i]>'0'&&s[i] <= '2'&&s[i + 1] <= '6') ret++;
	else
		for (int i = 0; i <= s.size()-2*n; i++)
			if (s[i]>'0'&&s[i] <= '2'&&s[i + 1] <= '6')
				ret += numDecodings(s, i + 2, n - 1);
	return ret;
}


int numDecodings2(string s) {
	if (s == ""||s[0]=='0') return 0;
	int n = s.size(), ret = s.find("0") != -1 ? 1 : 0;
	if (s.find("00")!= -1) return 0;
	for (int i = 1; i <= n/2; i++)
		ret+=numDecodings(s, 0, i)+(n-2*i>0&&s[n-1])?0:-1;
	return ret;
}




