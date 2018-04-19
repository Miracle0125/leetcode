

using namespace std;
#include"common.h"
#include<algorithm>


#define nth_4_bit(num,n) ((num&(15 << (4*n))) >> (4*n))
vector<int> countBits(int n) {
	vector<int> f{ 0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4 }, A(n + 1);
	for (int layer = 0, num = 0, limit =min(16,n); num<n; layer++)
	{
		for (; num < limit; num++)
		{
			for (int k = 0; k <= layer; k++)
			{
				A[num] += f[nth_4_bit(num, k)];
			}
		}
		limit = min(limit <<= 4, n);
		if (!limit) limit = n;
	}
	if (n < 16) A[n] = f[n];
	else 
	for(int i = n;i!=0;i>>=1){
		A[n] += i & 1;
	}
	return A;
}

//dp算法，逻辑是右移一位1数不变或者减一。简直造化钟神秀
vector<int> countBits2(int n) {
	vector<int> f(n + 1);
	for (int i = 1; i <= n; i++) f[i] = f[i >> 1] + (i & 1);
	return f;
}

//??
vector<int> countBits3(int num) {
	vector<int> ret(num + 1, 0);
	for (int i = 1; i <= num; ++i)
		ret[i] = ret[i&(i - 1)] + 1;
	return ret;
}


