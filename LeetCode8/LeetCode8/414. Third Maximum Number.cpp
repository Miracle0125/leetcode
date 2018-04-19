
#include"common.h"
#include<set>
int thirdMax(vector<int>& A) {
	set<int> s(A.begin(), A.end());
	if (s.size() < 3)return *(--s.end());
	return *(------s.end());
}
int thirdMax2(vector<int>& nums) {
	set<int> top3;
	for (const int& num : nums) {//??????
		top3.insert(num);
		if (top3.size() > 3) {
			top3.erase(top3.begin());
		}
	}
	return top3.size() == 3 ? *(top3.begin()) : *(top3.rbegin());
}