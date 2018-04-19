


using namespace std;
#include"common.h"



//自己想的方法，数学方法更快
#define op(left,x,y) (x-(y-left)%x)
bool canMeasureWater(int x, int y, int z) {
	if (y < x) swap(x, y);
	if (z == 0) return true;
	if (x == 0) return y == z;
	if ((y%x) == 0)return x + y == z || x == z || y == z;
	if (x + y < z) return false;
	map<int, int> m;
	for (int left = op(0, x, y); ++m[left] < 2; left = op(left, x, y))
		if ((z - left) % x == 0)return true;
	return false;
}