#include<vector>
#include<algorithm>
using namespace std;

//���������벻����.......
//ÿ���С����¡���ʱ��ͳ����һ���µ�������
int largestRectangleArea(vector<int> &height) {
	int ret = 0;
	height.push_back(0);
	vector<int> index;
	for (int i = 0; i < height.size(); i++)
	{
		//�ڶ�������������֤���ܽػ����³��֣����ܱ�֤stack����������Сɽ�ȵ�iֵ!
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