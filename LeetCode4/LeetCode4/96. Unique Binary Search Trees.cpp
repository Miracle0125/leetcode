#include<vector>
using namespace std;

vector<int> f;
int calculate(int n) {
	int ret=0, sum;
	for (int i = 1; i <= n / 2; i++)
		ret += (f[n - i] * (i - 1 >= 2 ? f[i - 1] : 1)) * 2;
	return ret + ((n & 1) ? f[n / 2] * f[n / 2] : 0);
}

int numTrees(int n) {
	 f= vector<int>(n+1, 1);
	f[2] = 2;
	f[3] = 5;
	if (n <= 3) return f[n];
	for (int i = 4; i <= n; i++) 
		f[i] = calculate(i);
	return f[n];
}

//为什么还没我的跑得快？
int numTrees2(int n) {
	vector<int> G(n + 1);
	G[0] = G[1] = 1;
	for (int i = 2; i <= n; ++i) 
		for (int j = 1; j <= i; ++j) 
			G[i] += G[j - 1] * G[i - j];
	return G[n];
}

int numTrees3(int n) {
	//cantalan树
	//C(2n,n)/(n+1)
	long long ans = 1;
	for (int i = n + 1; i <= 2 * n; i++) {
		ans = ans*i / (i - n);
	}
	return ans / (n + 1);
}