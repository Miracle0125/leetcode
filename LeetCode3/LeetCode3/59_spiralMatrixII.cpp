#include<vector>
//#include"common.h"
using namespace std;


bool inZoom(vector<vector<int>> &map,int x,int y){
	return x < map.size()&&y < map.size() &&x >= 0 && y >= 0 && !map[x][y];
}
bool go(vector<vector<int>> &map,int &direct, int &x, int &y, int times) {
	int x1 = x, y1 = y;
	if (direct > 3)
		direct = 0;
	switch (direct)
	{
	case 0:
		y1++;
		break;
	case 1:
		x1++;
		break;
	case 2:
		y1--;
		break;
	case 3:
		x1--;
		break;
	}
	if (inZoom(map,x1, y1)) {
		x = x1; y = y1;
	}
	else if (!times)
		return	go(map,++direct, x, y, times + 1);
	else return false;
	return true;
}

//与54类似  ，甚至比54还简单.....
vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> ret;
	if (n>0) {
		ret = vector<vector<int>>(n, vector<int>(n, 0));
		int x = 0, y = -1, direct = 0,i=1;
		while (go(ret,direct, x, y, 0))
			ret[x][y] = i++;
	}
	return ret;
}