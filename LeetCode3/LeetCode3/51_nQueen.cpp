#include<vector>
#include<iostream>
#include<string>
using namespace std;

bool isValid(vector<int> &l, int pos);
vector<string> getBlank(int n);

void init(vector<string> &v,vector<int>& l,int n){
	for (int i = 0; i < n-1; i++)
		v[i][l[i]] = 'Q';
}

void recurse(vector<vector<string>> &v,vector<int> &l, int layer,int n) {
	for (int i = 0; i < n; i++)
	{
		if (isValid(l, i)) {
			v[v.size() - 1][layer] = string(n, '.');
			v[v.size() - 1][layer][i] = 'Q';
			l[layer] = i;
			if (layer < n - 1) {
				recurse(v, l, layer+1, n);
				l[layer] = -1;
			}
			else {
				v.push_back(getBlank(n));
				init(v[v.size()-1], l, n);
			}
		}
	}
	if (layer == 0) 
		v.erase(v.end()-1);
	l[layer] = -1;
}

//write it by myself
vector<vector<string>> solveNQueens(int n) {
	if (n < 4) { 
		if(n==1) return vector<vector<string>>{ {"Q"}};
		return vector<vector<string>>{ }; 
	}
	vector<vector<string>> ret;
	vector<int> l(n,-1);
	ret.push_back(getBlank(n));
	recurse(ret,l,0,n);
	return ret;
}


bool isValid(vector<int> &l,int pos) {
	int j, n = l.size(),y;
	//这段应该可以去掉，可是去掉后会出错
	for (int i = 0; i < n; i++)
		if (l[i] == -1) n = i;
	for (int i = 0; i < n; i++)
	{	
		if ((y = l[i]) == -1) break;
		if (pos == y || y + (n - i) == pos || y - (n - i) == pos) return false; 
	}
	return true;
}

vector<string> getBlank(int n){
	return 	vector<string> (n, string(n, '.'));
}

//int main() {
//	solveNQueens(5);
//	system("pause");
//}