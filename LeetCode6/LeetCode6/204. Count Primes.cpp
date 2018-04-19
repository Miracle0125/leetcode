
#include<vector>
using namespace std;


vector<int> calcPrimeNumbers(int n) {
	if (--n < 2) return vector<int>{};
	vector<int> ret = { 2 };
	for (int i = 3,j; i <= n; i++)
	{
		for (j=0; j < ret.size(); j++)
		{
			if (i%ret[j] == 0) break;
		}
		if (j == ret.size()) ret.push_back(i);
	}
	return ret;
}

int countPrimes(int n) {
	int ret = 0;
	vector<bool> f(n);
	for (int i = 2; i < n; i++)
	{
		if (!f[i]) ret++;
		for (int j = 2; i*j<n; j++)
			f[i*j] = true;
	}
	return ret;
}

//
//int main() {
//	vector<int> ret = calcPrimeNumbers(1000);
//	return 0;
//}