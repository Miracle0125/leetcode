#include<bitset>
#include<vector>
#include<stack>
#include<math.h>
#include"common.h"
using namespace std;


//G(i) = i^ (i/2).
//琢磨了半天，原来是有公式的
vector<int> grayCode(int n) {
	vector<int> ret;
	for (int i = 0; i < 1<<n; i++)
		ret.push_back(i^i >> 1);
	return ret;
}


//vector<int> grayCode(int n) {
//	int sum = pow(2, n);
//	vector<int> ret, cache;
//	//stack<int> cache;
//	for (int i = 0x0; i < sum; i++)
//	{
//		if(cache.empty()|| cache.back() != i)
//			ret.push_back(i);
//		else cache.erase(cache.end()-1);
//		if (i & 1) {
//			int k = 0;
//			for (int j = 0; j < sum; j++)
//				if (i&(1 << j)) k++; else break;
//			int tmp = i | (1 << k);
//			if (find(cache.begin(), cache.end(),tmp) != cache.end()) continue;
//			ret.push_back(tmp);
//			cache.push_back(tmp);
//			for (int j = 0; tmp!=i+1; j++)
//			{
//				if (tmp&(1 << j)) { 
//					tmp &= ((sum-2) << j); 
//					ret.push_back(tmp);
//					cache.push_back(tmp);
//				}
//			}
//		}
//	}
//	printMatrix(ret);
//	return ret;
//}