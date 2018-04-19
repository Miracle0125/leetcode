
#include"common.h"


int r = 0;
void dfs(int t, int coin, vector<int>&A) {
	if (t == 0) r++;
	else if (coin == 0) {
		if (t%A[coin] == 0)r++;
	}
	else {
		for (int i = t / A[coin]; i >= 0; i--)
		{
			dfs(t - i * A[coin], coin - 1, A);
		}
	}
}

int change(int t, vector<int>& coins) {
	sort(coins.begin(), coins.end());
	if (t == 0 ) return 1;
	if (coins.empty() || coins[0] > t) return 0;
	int max_coin = coins.size() - 1;
	for (int i = 0; i < coins.size(); i++)
	{
		if (coins[i] > t) {
			max_coin = i - 1; break;
		}
	}
	dfs(t, max_coin, coins);
	return r;
}


//int main() {
//	vector<int> v{ 3,5,7,8,9,10,11 };
//	change(1000, v);
//	return 0;
//}

