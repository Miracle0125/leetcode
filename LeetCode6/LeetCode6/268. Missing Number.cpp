
#include"common.h"
#include<vector>
#include<map>
using namespace std;



//做这题真是yuelegoule
int missingNumber(vector<int>& A) {
	if (!A.size()) return 0;
	A.push_back(0);
	for (int i = 0; i < A.size(); i++)
		if(A[i]!=i)
			swap(A[i],A[A[i]]);
	map<int, int> map;
	for (int i = 0; i < A.size(); i++) 
		if (A[i] != i) { map[A[i]]++; map[i]++; }
	for (auto i = map.begin(); i != map.end(); i++)
		if (i->first&&i->second == 1) return i->first;
	return 0;
}


int missingNumber2(vector<int>& A) {
	int xor = 0, i = 0;
	for (i = 0; i < A.size(); i++) {
		xor = xor ^ i ^ A[i];
	}
	return xor ^ i;
}



//
//int main() {
//auto ret=	missingNumber(vector<int> {9, 6, 4, 2, 3, 5, 7, 0, 1});
//	return 0;
//}