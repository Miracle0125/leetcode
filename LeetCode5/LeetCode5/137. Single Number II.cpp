
#include<vector>
using namespace std;

//这种看起来简单要求复杂的题其实很难.......
int singleNumber(vector<int> &A) {
	int ones = 0, twos = 0;
	for (int i = 0; i < A.size(); i++) {
		ones = (ones ^ A[i]) & ~twos;
		twos = (twos ^ A[i]) & ~ones;
	}
	return ones;
}