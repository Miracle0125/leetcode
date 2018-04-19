#include<vector>
#include<algorithm>
using namespace std;


//7, 1, 5, 3, 6, 4
int maxProfit_122(vector<int>& A) {
	int sum = 0;
	for (int i = 1; i < A.size(); i++)
		sum += max(0, A[i] - A[i - 1]);
	return sum;
}