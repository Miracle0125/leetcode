
#include"common.h"
#include<set>
#include<bitset>
bool canPartition(vector<int>& A) {
	int sum = 0, n = A.size(), i = 0;
	if (n == 2)return A[0] == A[1];
	for (const int& i : A)sum += i;
	if (sum % 2)return false;
	sum /= 2;
	set<int> nums;
	while (A[i] > sum)i++;
	nums.insert(A[i++]);
	for (; i < n; i++)
	{
		if (A[i] == sum) return true;
		vector<int> temp;
		for (const int& j : nums) {
			int addition = j + A[i];
			if (addition < sum) temp.push_back(addition);
			else if (addition > sum) break;
			else return true;
		}
		nums.insert(temp.begin(), temp.end());
		if(A[i]<sum)
			nums.insert(A[i]);
	}
	return false;
}

//best 9ms  ,É§µ½Ã»ÅóÓÑ
bool canPartition2(vector<int>& nums) {
	const int MAX_NUM = 100;
	const int MAX_ARRAY_SIZE = 200;
	bitset<MAX_NUM * MAX_ARRAY_SIZE / 2 + 1> bits(1);
	int sum = 0;
	for (auto n : nums) {
		sum += n;
		bits |= bits << n;
	}
	return !(sum % 2) && bits[sum / 2];
}