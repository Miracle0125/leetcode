
#include<vector>
using namespace std;

//异或运算是可以交替的！！！    顺序可以不同
int singleNumber(vector<int> &A, int n) {
	int result = 0;
	for (int i = 0; i<n; i++)
	{
		result ^= A[i];
	}
	return result;
}