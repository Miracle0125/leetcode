
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//«’∂® π”√Õ∞≈≈–Ú
int maximumGap(vector<int>& A) {
	if (A.size() < 2)return 0;
	if (A.size() == 2) return abs(A[0]-A[1]);
	int low=A[0], hi=A[0],n=A.size();
	for (int i = 1; i < n; i++)
	{
		low = min(A[i], low);
		hi = max(A[i], hi);
	}
	if (hi == low) return 0;
	float gap = float(hi - low) / (n - 1);
	vector<vector<int>> buckets(n - 1);
	for (int i = 0; i < n; i++)
	{
		int l = 0, r = n - 2;
		while (l <= r) {
			int	k = (l + r) / 2;
			if (A[i] < low + (k)*gap)
				r = k;
			else if (A[i] >= low + (k + 1)*gap&&k != n - 2)
				l = k + 1;
			else {
				if (buckets[k].size() == 2) {
					if (A[i] < buckets[k][0])
						buckets[k][0] = A[i];
					else if (A[i] > buckets[k][1])
						buckets[k][1] = A[i];
				}
				else if (buckets[k].size() == 1 && buckets[k][0] > A[i])
					buckets[k].insert(buckets[k].begin(), A[i]);
				else buckets[k].push_back(A[i]);
				break;
			}
		}
	}
	int max_gap = INT_MIN,l=0,r=l+1;
	while (r < buckets.size()) {
		if (buckets[r].size() > 0) {
			max_gap = max(max_gap, buckets[r][0] - buckets[l][buckets[l].size() - 1]);
			l = r;
		}
		r++;
	}
	return max_gap;
}


//int main() {
//	float t = float(3)/2;
//
//	vector<int> A;
//	for (int i = 0; i < 100; i++)
//	{
//		A.push_back((rand() % (0 - 600)));
//	}
//	maximumGap(A);
//	return 0;
//	
//}