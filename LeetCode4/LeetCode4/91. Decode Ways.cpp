#include<string>
#include<vector>

using namespace std;

//For example, the String now is "123xxxx" and we know all the result from 2. 
//Because 12<26, we can make this string either"12"+"3xxxx" or 1+23xxxx 
//看了这个dp代码，我觉得我原来写的就是坨shit
//违反直觉的代码，非常快.  从尾部开始一步步积累，不太明白 为什么  memo[i] = memo[i + 1] + memo[i + 2]
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



//me  这个结构的程序真是屡试不爽..   但是不成功
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




