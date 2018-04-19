#include<vector>
#include<algorithm>
using namespace std;

//这题是真想不出了.......
//每当有“下坡”的时候，统计上一个坡的最大面积
int largestRectangleArea(vector<int> &height) {
	int ret = 0;
	height.push_back(0);
	vector<int> index;
	for (int i = 0; i < height.size(); i++)
	{
		//第二个条件不仅保证了能截获下坡出现，还能保证stack里留存有最小山谷的i值!
		while (index.size() > 0 && height[index.back()] >= height[i])
		{
			int h = height[index.back()];
			index.pop_back();
			ret = max(ret, h*(i - 1 - (index.size() > 0 ? index.back() : -1)));
		}
		index.push_back(i);
	}
	return ret;
}


//int main() {
//	int ret  = largestRectangleArea(vector<int> {2,1,5,6,5,6,1});
//	return ret;
//}