#include<vector>

#include"common.h"
using namespace std;


//Ϊʲô��while������if��  ��Ե�һ��Ϊ0 �������ر�д����������ͷ��0��
void sortColors(vector<int>& A) {
	int n = A.size(),l=0,r=n-1;
	for (int i = 0; i <= r; i++)
	{
		//ǰ��˳�����Ҫ
		while (A[i] == 2 && i < r) swap(A[i], A[r--]);
		while (A[i] == 0 && i > l) swap(A[i], A[l++]);
	}
}