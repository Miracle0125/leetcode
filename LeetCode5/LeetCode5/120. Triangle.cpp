#include<vector>
#include<algorithm>
using namespace std;



//�ӵ����ڶ��㿪ʼ�����㾭��ÿ��ͨ�������i��������·��������
//amazing code!  amazing dp!
int minimumTotal(vector<vector<int> > &triangle) {
	int n = triangle.size();
	vector<int> minlen(triangle.back());
	for (int layer = n - 2; layer >= 0; layer--) // For each layer
		for (int i = 0; i <= layer; i++) // Check its every 'node'
			minlen[i] = min(minlen[i], minlen[i + 1]) + triangle[layer][i];
	return minlen[0];
}