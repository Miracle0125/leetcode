#include"common.h"
#include<vector>
#include<string>
using namespace std;

	void printMatrix(vector<vector<string>> &v) {
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = 0; j < v[i].size(); j++)
			{
				cout << v[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}


	//写的和高票答案差不多了，模仿优化了一下
	vector<vector<string>> ret;
	bool isPalindrome(string& str, int l, int r) {
		if (l == r) return true;
		while (l<r) {
			if (str[l] != str[r]) return false;
			l++; r--;
		}
		return true;
	}

	void dfs(int index, string& s, vector<string>& v) {
		if (index == s.length()) {
			ret.push_back(v);
			return;
		}
		for (int i = index; i < s.length(); i++)
			if (isPalindrome(s, index, i)) {
				v.push_back(s.substr(index, i - index + 1));
				dfs(i + 1, s, v);
				v.pop_back();
			}
	}
	vector<vector<string>> partition(string s) {
		if (!s.empty())
			dfs(0, s, vector<string>{});
		//printMatrix(ret);
		return ret;
	}




//int main() {
//	string s = "dadabcbz";
//	partition("dadabcbz");
//	string ss = s.substr(1, 1);
//	return 1;
//}