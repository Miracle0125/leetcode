#include"common.h"
#include<vector>
#include<algorithm>

using namespace std;

//tmpMax 代表买入后剩余的钱
int maxProfit(vector<int> &prices) {
	// f[k, ii] represents the max profit up until prices[ii] (Note: NOT ending with prices[ii]) using at most k transactions. 
	// f[k, ii] = max(f[k, ii-1], prices[ii] - prices[jj] + f[k-1, jj]) { jj in range of [0, ii-1] }
	//          = max(f[k, ii-1], prices[ii] + max(f[k-1, jj] - prices[jj]))
	// f[0, ii] = 0; 0 times transation makes 0 profit
	// f[k, 0] = 0; if there is only one price data point you can't make any money no matter how many times you can trade
	if (prices.size() <= 1) return 0;
	else {
		int K = 2; // number of max transation allowed
		int maxProf = 0;
		vector<vector<int>> f(K + 1, vector<int>(prices.size(), 0)),f1=f;
		for (int kk = 1; kk <= K; kk++) {
			int tmpMax = f[kk - 1][0] - prices[0];
			for (int ii = 1; ii < prices.size(); ii++) {
				//代表两种行为：卖出或者不卖出
				f[kk][ii] = max(f[kk][ii - 1], prices[ii] + tmpMax);
				//想办法在买入后剩余最多的钱
				tmpMax = max(tmpMax, f[kk - 1][ii] - prices[ii]);
				f1[kk][ii] = tmpMax;
				maxProf = max(f[kk][ii], maxProf);
			}
		}
		printMatrix(f);
		printMatrix(f1);
		return maxProf;
	}
}

/*
0  0  0  0  0  0  0  0
0  0  2  2  2  3  3  4
0  0  2  2  2  5  5  6
0  0  2  2  2  5  5  8
3, 3, 5, 0, 0, 3, 1, 4
//	maxProfit(vector<int>{});
为什么能做到规避开重复的交易？   因为重复的交易得不到更大的余额

0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  7  7  7  7  8  14 14 14 14 19 19 19
0  0  0  7  7  7  7  15 21 21 21 21 32 32 32
0  0  0  7  7  7  7  15 21 21 21 21 39 39 39
8, 4, 4, 11, 4, 2, 0, 8, 14, 7, 7, 1, 19, 10, 8

*/


//int maxProfit(vector<int> &prices) {
//	int hold1 = INT_MIN, hold2 = INT_MIN;
//	int release1 = 0, release2 = 0;
//	for (int i : prices) {                              // assume we only have 0 money at first
//		release2 = max(release2, hold2 + i);     // the maximum if we've just sold 2nd stock so far.
//		hold2 = max(hold2, release1 - i);  // the maximum if we've just buy  2nd stock so far.
//		release1 = max(release1, hold1 + i);     // the maximum if we've just sold 1nd stock so far.
//		hold1 = max(hold1, -i);          // the maximum if we've just buy  1st stock so far. 
//		cout << release2 << " " << hold2 << " " << release1 << " " << hold1 << endl;
//	}
//	return release2; ///since release1 is initiated as 0, so release2 will always higher than release1.
//}




//int maxProfit(vector<int> &A) {
//	int K = 2;
//	vector<vector<int>> f(K + 1, vector<int>(A.size(), 0));
//	for (int i = 1; i <= K; i++)
//	{
//		int curMax = 0;
//		for (int j = 1; j < A.size(); j++)
//		{
//			curMax = max(0, curMax + A[i] - A[i - 1]);
//			f[i][j] = max(f[i][j - 1], curMax);
//
//		}
//	}
//}

//int main() {
//
//	maxProfit(vector<int>{8, 4, 4, 11, 4, 2, 0, 8, 14, 7, 7, 1, 19, 10, 8});
//		//maxProfit(vector<int>{3, 3, 5, 0, 0, 3, 1, 4});
//	return 1;
//}
/*
11
18
5
7
13
4
6
18
13
4
4
16
6
10
12*/

//int one = 0,two = 0;

//void check(int n) {
//	if (n > two) {
//		if (n > one) {
//			two = one;
//			one = n;
//		}
//		else two = n;
//	}
//	else return;
//}
//
//int maxProfit(vector<int>& A) {
//	int cur;
//	for (int i = 1; i < A.size(); i++)
//	{
//		cur = max(0,cur+=A[i] - A[i - 1]);
//		if (cur > 0) check(cur);
//	}
//	return one + two;
//}