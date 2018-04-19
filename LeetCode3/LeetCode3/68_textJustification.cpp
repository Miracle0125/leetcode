#include<vector>
#include<string>
#include<iostream>
using namespace std;

void printMatrix(vector<string> &v) {
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	cout << endl;
}

//比较考验细节的把握
vector<string> fullJustify(vector<string>& A, int max) {
	vector<string> ret;
	int len = -1, start = 0, space = 0, nums, i = 0,n=A.size(),l=0;
	bool mark = false;
	for (i = 0; i < n; i++)
	{
		len += A[i].length()+1;
		if (len > max||(mark=i==n-1)) {
			space = max;
			nums = i - start-1;
			//if (!nums) nums = 1;
			for (int j = start; j < i; j++)
				space -= A[j].length();
			string s="";
			if (mark) {
				for (int j = start; j < n; j++) {
					s += A[j];
					if (s.length() < max) s += " ";
				}
				s+= string(max - s.length(), ' ');
				ret.push_back(s);
				break;
			}
			if (nums>0) {
				for (int j = i - 1; j > start; j--) {
					l = space / nums--;
					space -=l;
					s.insert(0, string(l, ' ') + A[j]);
				}
				s.insert(0, A[start]);
			}
			else {
				s += A[start] + string(max - A[start].length(), ' ');
			}
			ret.push_back(s);
			start = i;
			i--;
			len = -1;
			l = 0;
		}
	}
	return ret;
}