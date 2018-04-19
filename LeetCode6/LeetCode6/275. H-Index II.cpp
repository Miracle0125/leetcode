

#include"common.h"
#include<vector>
#include<algorithm>
using namespace std;



int hIndex(vector<int>& A) {
	if (!A.size()) return 0;
	int i = 0,n=A.size();
	for (; i < A.size() && A[n-1-i] >= i + 1; i++);
	return i;
}