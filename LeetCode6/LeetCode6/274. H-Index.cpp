

#include"common.h"
#include<vector>
#include<algorithm>
using namespace std;

class _274 {
	static bool cmp(int a, int b) { return a > b; }
	int hIndex(vector<int>& A) {
		if (!A.size()) return 0;
		sort(A.begin(), A.end(), cmp);
		int i = 0;
		for (; i < A.size() && A[i] >= i + 1; i++);
		return i;
	}

	//Õ®≈≈–Ú
	int hIndex2(vector<int>&citations) {
		int n = citations.size();
		vector<int> buckets(n + 1);
		for (int c : citations)
			c >= n ? buckets[n]++ : buckets[c]++;
		int count = 0;
		for (int i = n; i >= 0; i--)
			if ((count += buckets[i]) >= i)
				return i;
		return 0;
	}
};
 
