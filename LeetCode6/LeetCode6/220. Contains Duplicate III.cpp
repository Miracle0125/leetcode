

#include<vector>
#include<algorithm>
#include<set>
using namespace std;


//overflow
//long 32bit 4byte 64bit 8byte
bool containsNearbyAlmostDuplicate(vector<int>& A, int k, int t) {
	set<long> window;
	for (int i = 0; i < A.size(); i++)
	{
		if (i > k) window.erase(A[i - k - 1]);
		auto pos = window.lower_bound(A[i] - long(t));//-t <= x - A[i] <= t      so   x>=A[i]-t && x<=A[i]+t
		if (pos != window.end() && *pos <= long(t)+A[i]) return true;
		window.insert(long(A[i]));
	}
	return false;
}



//time limit exceeded  O(n^2)
//bool containsNearbyAlmostDuplicate(vector<int>& A, int k, int t) {
//	if (A.size()&&k) {
//		for (int i = 0; i < A.size() - 1; i++)
//		{
//			for (int j = i+1; j <= i+k&&j<A.size(); j++)
//			{
//				if (abs(A[i] - A[j]) <= t) {
//					int ret = A[i] - A[j], a = A[i] >> 31,b = A[j] >> 31;
//					if (!(ret == INT_MIN || (a != b&&a != ret >> 31)))
//					return true;
//				}
//			}
//		}
//	}
//	return false;
//}

