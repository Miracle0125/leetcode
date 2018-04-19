

using namespace std;
#include"common.h"




void lexicalOrder(int m,int n,vector<int> &v) {
	if ((m*=10)<=n) {
		for (int i = m, limit = min(m + 9, n); i <= limit; i++) {
			v.push_back(i);
			lexicalOrder(i, n, v);
		}
	}
}
//myself,149ms
vector<int> lexicalOrder(int n) {
	vector<int> v;
	for (int i = 1, limit = min(n, 9); i <= limit; i++)
	{
		v.push_back(i);
		lexicalOrder(i, n, v);
	}
	return v;
}


//119ms
vector<int> lexicalOrder2(int n) {
	vector<int> ans(n);
	int num = 1;
	for (int i = 0; i < n; ++i) {
		ans[i] = num;
		if (10 * num <= n) {
			num *= 10;
		}
		else {
			if (num == n)
				num /= 10;
			++num;
			while (num % 10 == 0)
				num /= 10;
		}
	}
	return ans;
}