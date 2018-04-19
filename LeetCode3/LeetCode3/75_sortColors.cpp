#include<vector>

#include"common.h"
using namespace std;


//为什么用while而不用if？  针对第一个为0 ，不用特别写程序跳过开头的0。
void sortColors(vector<int>& A) {
	int n = A.size(),l=0,r=n-1;
	for (int i = 0; i <= r; i++)
	{
		//前后顺序很重要
		while (A[i] == 2 && i < r) swap(A[i], A[r--]);
		while (A[i] == 0 && i > l) swap(A[i], A[l++]);
	}
}