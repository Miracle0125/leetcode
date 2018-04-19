#include<vector>
#include<algorithm>
using namespace std;

//非常神奇的算法   9ms
int maxSubArray2(vector<int>& A) {
	int maxSoFar = A[0], maxEndingHere = A[0];
	for (int i = 1; i<A.size(); ++i) {
		maxEndingHere = max(maxEndingHere + A[i], A[i]);
		maxSoFar = max(maxSoFar, maxEndingHere);
	}
	return maxSoFar;
}

//-2,1,-3,4,-1,2,1,-5,4


//我想在原有最高值区块和新最高值区块之间可能存在非常低的负值，就像深渊一样   ，？？？
//write it by myself    86ms
int maxSubArray(vector<int>& nums) {
	int max = nums[0];
	int l = 0, r = 0, temp_l = 0, temp_max;
	for (int pos = 0; pos < nums.size(); pos++)
	{
		bool through = false;
		if (max >= 0) {
			if (nums[pos] <= 0) continue;
			if (r == pos - 1) { max += nums[pos]; r++; continue; }
		}
		int cache = 0;
		for (int i = pos; i >=l; i--)
		{
			if ((cache += nums[i]) > max) {
				r = pos;
				temp_l = i;
				//temp_max = max;
				max = cache;
				through = true;
			}
		}
		if (through) l = temp_l;
		//cache>0? max = temp_max + cache: l = temp_l;
	}
	return max;
}

//int main() {
//	maxSubArray2(vector<int>{-2, 1, -3, 4, -1, 2, 1, -5, 4});
//
//}