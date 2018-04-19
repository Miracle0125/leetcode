#include<vector>
#include<algorithm>
using namespace std;

int m, n;
vector<vector<int>> map;
bool inZoom(int x, int y) {
	return x < m&&y < n&&x>=0&&y>=0&&!map[x][y];
}

bool go(int &direct,int &x,int &y,int times) {
	int x1=x, y1=y;
	if (direct > 3) 
		direct=0;
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
	if (inZoom(x1, y1)) {
		x = x1; y = y1;
	}
	else if (!times)
		return	go(++direct, x, y, times + 1);
	else return false;
	return true;
}

vector<int> spiralOrder(vector<vector<int>>& mat) {
	vector<int> ret;
	if (mat.size() != 0 && mat[0].size() != 0) {
		m = mat.size(), n = mat[0].size();
		map = vector<vector<int>>(m, vector<int>(n, 0));
		int x = 0, y = -1, direct = 0;
		while (go(direct, x, y, 0)) {
			ret.push_back(mat[x][y]);
			map[x][y] = 1;
		}
	}
	return ret;
}


//int main() {
//	spiralOrder(vector<vector<int>>{
//		{1, 2, 3},
//		{ 4, 5, 6 },
//		{7, 8, 9}
//	});
//	//spiralOrder(vector<vector<int>>{ });
//
//}