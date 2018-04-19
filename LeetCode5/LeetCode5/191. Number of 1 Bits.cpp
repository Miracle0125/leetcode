
#include<string>
#include<iostream>

using namespace std;

typedef unsigned int uint32_t;

int hammingWeight(uint32_t n)
{
	int times = 0;
	int res = 0;
	while (n)
	{
		n &= n - 1;
		++res;
		cout << ++times << endl;
	}
	return res;
}

//int main() {
//	
//	hammingWeight(241465498);
//	return 1;
//}