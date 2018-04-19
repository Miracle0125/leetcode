#include"common.h"
#include<vector>
#include<stack>
#include<iostream>
#include<unordered_map>
using namespace std;


//用到一个全排列公式：    Cmn = C(m-1)(n-1)+C(m-1)(n)   .....

int numDistinct(string S, string T) {
	vector<vector<int>> mem(T.length() + 1,vector<int>(S.length() + 1,0));
	for (int j = 0; j <= S.length(); j++) 
		mem[0][j] = 1;
	for (int i = 0; i<T.length(); i++) 
		for (int j = 0; j<S.length(); j++) 
			if (T[i] == S[j]) 
				mem[i + 1][j + 1] = mem[i][j] + mem[i + 1][j];
			else 
				mem[i + 1][j + 1] = mem[i + 1][j];
	return mem[T.length()][S.length()];
}


//
//struct KV
//{
//	char key;
//	int val;
//	KV(char c, int i) : key(c), val(i) {};
//	KV() :key(0), val(0) {};
//};
//
//void printMatrix(vector<KV> v) {
//	for (int i = 0; i < v.size(); i++)
//	{
//		cout << v[i].val << " ";
//	}
//	cout << endl;
//}
//
//
//
//int fac(int n) {
//	if (n == 1 || n == 0)
//		return 1;
//	return fac(n - 1)*n;
//}
//
//int getPermutation(int m,int n){
//	if (m == n) return 1;
//	if (n == 0) return 0;
//	if (n == 1) return m;
//	if (n > m - n) n = m - n;
//	return fac(m)/(fac(n)*fac(m-n));
//}
//
//vector<KV> getMap(string t){
//	vector<KV> map;
//	KV kv;
//	for (int i = 0; i < t.size(); i++)
//	{
//		kv = KV(t[i], 1);
//		while (i + 1 < t.size() && t[i + 1] == t[i]) {
//			kv.val++;
//			i++;
//		}
//		map.push_back(kv);
//	}
//	return map;
//}
//
//int numDistinct(string s, string t) {
//	int m = s.size(), count = 0;;
//	vector<KV> map	= getMap(t);
//	vector<int> f(m+1, 0);
//	for (int j = 0; j < s.length(); j++) {
//		if (map[0].key == s[j]) { 
//			count++; 
//			if(count>= map[0].val)
//			f[j + 1] = getPermutation(count, map[0].val); }
//		else f[j + 1] = f[j] * (count >= map[0].val ? 1 : 0);
//
//	}
//		printMatrix(f);
//	for (int i = 1; i < map.size(); i++) {
//		count = 0;
//		for (int j = 0; j < s.length(); j++) {
//			if (map[i].key == s[j]&&f[j+1]) {
//				count++;
//				if (count >= map[i].val) f[j + 1] = getPermutation(count, map[i].val)* (f[j + 1] ? f[j + 1] : 0);
//			}
//			else f[j + 1] = f[j] * (count>=map[i].val ? 1 : 0);	
//		}
//		printMatrix(f);
//	}
//	
//	return f[m];
//}
//
//int main() {
//	numDistinct("daacaedaceacabbaabdccdaaeaebacddadcaeaacadbceaecddecdeedcebcdacdaebccdeebcbdeaccabcecbeeaadbccbaeccbbdaeadecabbbedceaddcdeabbcdaeadcddedddcececbeeabcbecaeadddeddccbdbcdcbceabcacddbbcedebbcaccac", "ceadbaa");
//	//vector<KV> map=	getMap("ceadbaa");
//	//printMatrix(map);
//	return 1;
//}

//if (map[i].val == 1)
//	for (int j = 0; j < s.length(); j++)
//	{
//		if (map[i].key == s[j] && f[j + 1]) f[j + 1] *= (++count);
//		else f[j + 1] = f[j] * (count ? 1 : 0);
//	}


//int numDistinct(string s, string t) {
//	int ret = 0;
//	if (t == "") return s == "" ? 1 : 0;
//	if (t.length() == 1)
//		for (int i = 0; i < s.length(); i++)
//			if (s[i] == t[0])
//				ret++;
//	else {
//		
//		string key = "";
//		for (int i = 0; i < t.length(); i++)
//			if (key.find(t[i]) == -1) key.push_back(t[i]);
//		vector<vector<int>> hight_light(key.length());
//		for (int i = 0; i < s.length(); i++)
//		{
//			int index = key.find(s[i]);
//			if (index != -1) hight_light[index].push_back(i);
//		}
//		int numOfHeads = hight_light[0].size();
//		int pos = 1;
//		for (int i = 0; i < numOfHeads; i++)
//		{
//			
//			//if(hight_light[pos])
//		}
//		int len_src = s.length(),len=  t.length();
//		stack<int> head, tail;
//		int first = s.find(t[0]);
//		if (first == -1) break;
//		s = s.substr(first, len_src);
//
//	}
//	return ret;
//}

