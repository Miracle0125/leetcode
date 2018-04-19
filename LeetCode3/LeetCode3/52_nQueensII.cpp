#include<vector>
#include<iostream>
#include<string>
#include"common.h"
using namespace std;


void totalNQueens(vector<vector<string>> &v, vector<int> &l, int layer, int n,int& sum) {
	for (int i = 0; i < n; i++)
	{
		if (isValid(l, i)) {
			l[layer] = i;
			if (layer < n - 1) {
				totalNQueens(v, l, layer + 1, n, sum);
				l[layer] = -1;
			}
			else {
				v.clear();
				v.push_back(vector<string>(n, string(n, '.')));
				sum++;
			}
		}
	}
	l[layer] = -1;
}

int totalNQueens(int n) {
	if (n < 4) return n == 1 ? 1 : 0;
	vector<vector<string>> ret;
	vector<int> l(n, -1);
	int sum = 0;
	ret.push_back(vector<string>(n, string(n, '.')));
	totalNQueens(ret, l, 0, n, sum);
	return sum;
}

//int main() {
//	totalNQueens(5);
//	system("pause");
//}