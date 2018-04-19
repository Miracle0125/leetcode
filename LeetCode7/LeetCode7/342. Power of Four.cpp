
#include"common.h"
#include<set>
using namespace std;
bool isPowerOfFour(int n) {
	int v[] = {
		1
		,4
		, 16
		, 64
		, 256
		, 1024
		, 4096
		, 16384
		, 65536
		, 262144
		, 1048576
		, 4194304
		, 16777216
		, 67108864
		, 268435456
		, 1073741824 };
	for (int i = 0; i < 16&&v[i]>=n; i++)
		if (n == v[i]) return true;
	return false;
}



//ɧ
bool isPowerOfFour2(int num) {
	return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
}