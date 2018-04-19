#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;



//write this by myself,  but the sequense dosen't match the anwser
//it more faster than the best solution      n=10,480ms+
vector<string> generateParenthesis(int n) {
	vector<string> r;
	if (n == 0) return r;
	if (n == 1) { r.push_back("()"); return r; }
	r = generateParenthesis(n - 1);
	vector<string> cache;
		for (int i = 0; i < r.size(); i++)
		{
			cache.push_back("(" + r[i] + ")");
			cache.push_back("()" + r[i]);
			cache.push_back(r[i] + "()");
		}
		cache.erase(cache.end()-1);
	return cache;
}


void addingpar(vector<string> &v, string str, int n, int m) {
	if (n == 0 && m == 0) {
		v.push_back(str);
		return;
	}
	if (m > 0) { addingpar(v, str + ")", n, m - 1); }
	if (n > 0) { addingpar(v, str + "(", n - 1, m + 1); }
}
//leetCode 上的最佳解，不过用时太久，n=10     1480ms+
vector<string> generateParenthesis2(int n) {
	vector<string> res;
	addingpar(res, "", n, 0);
	return res;
}


//int main() {
//	vector<string> r = generateParenthesis(10);
//	r.clear();
//	 r = generateParenthesis2(10);
//	//string a[] = { "()()()()","(()()())","(()())()","((()()))","()(()())","(())()()","((())())","()(())()","((()))()","(((())))","()((()))","()(())()","(()(()))","()()(())" };
//	string b[] = { "(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()",     "(())(())","(())()()",     "()((()))","()(()())","()(())()","()()(())","()()()()"};
//	////vector<string> s(a, a + sizeof(a) / sizeof(string));
//	//for (int i = 0; i < sizeof(b)/sizeof(string); i++)
//	//{
//	//	string s = b[i];
//	//	for (int j = 0; j < sizeof(a) / sizeof(string); j++)
//	//	{
//	//		if (a[j] == s) break;
//	//		else if (j == sizeof(a) / sizeof(string))
//	//			cout << s << endl;
//	//	}
//	//}
//	
//	system("pause");
//}