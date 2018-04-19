

using namespace std;
#include"common.h"
#include<algorithm>



int combinationSum4(vector<int>& A, int t) {
		sort(A.begin(), A.end());
		vector<int> f(t + 1); f[0] = 1;
		for (int i=1; i <= t; i++)
			for (auto j = A.begin(); j != A.end() &&i >= *j ; j++)
				f[i] += f[i - *j];
		return f[t];
}





