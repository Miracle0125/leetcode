#include<vector>
#include<algorithm>
using namespace std;


//有其独到之处   Kadane's Algorithm
//int maxProfit(vector<int>& prices) {
//	int maxCur = 0, maxSoFar = 0;
//	for (int i = 1; i < prices.size(); i++) {
//		maxCur = max(0, maxCur += prices[i] - prices[i - 1]);
//		maxSoFar = max(maxCur, maxSoFar);
//	}
//	return maxSoFar;
//}


int maxProfit_121(vector<int>& A) {
	int profit = 0;
	if (!A.empty()) {
		int minnum = A[0];
		for (int i = 1; i < A.size(); i++)
		{
			if (A[i] > A[i - 1]) profit = max(profit,A[i]- minnum);
			else minnum = min(A[i], minnum);
		}
	}
	return profit;
}