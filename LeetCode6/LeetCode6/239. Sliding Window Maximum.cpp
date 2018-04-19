

#include"common.h"
#include<vector>
#include<deque>
using namespace std;



vector<int> maxSlidingWindow(vector<int>& A, int k) {
	deque<int> q;
	vector<int> ret;
	for (int i = 0; i < A.size(); i++)
	{
		if (!q.empty()&&q.front() < i - k + 1) q.pop_front();
		while (1) {
			if (!q.empty()&& A[q.back()] <= A[i]) {
				 q.pop_back();
				 continue; 
			}
			q.push_back(i);
			break;
		}
		if (i >= k - 1) ret.push_back(A[q.front()]);
	}
	return ret;
}