


#include<vector>
#include"common.h"
using namespace std;

//从右到左
//为什么这个还比我的慢？
//vector<int> getRow(int rowIndex) {
//	vector<int> A(rowIndex + 1, 0);
//	A[0] = 1;
//	for (int i = 1; i<rowIndex + 1; i++)
//		for (int j = i; j >= 1; j--)
//			A[j] += A[j - 1];
//	return A;
//}


vector<int> getRow(int n) {
	vector<int> ret(n+1,1);
	if (n > 2) {
		ret[1] = 2;
		int pre, tmp, j;
		for (int i = 4; i <= n+1; i++)
		{
			pre = 1;
			for (j = 1; j < i - 2; j++)
			{
				tmp = ret[j];
				ret[j] = ret[j] + pre;
				pre = tmp;
			}
			ret[j] = pre + 1;
		}
	}
	else if (n == 2) ret[1] = 2;
	return ret;
}