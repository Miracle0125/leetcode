#include<vector>
#include<algorithm>
using namespace std;



//从倒数第二层开始，计算经过每层通过当层第i个点的最短路径并保存
//amazing code!  amazing dp!
int minimumTotal(vector<vector<int> > &triangle) {
	int n = triangle.size();
	vector<int> minlen(triangle.back());
	for (int layer = n - 2; layer >= 0; layer--) // For each layer
		for (int i = 0; i <= layer; i++) // Check its every 'node'
			minlen[i] = min(minlen[i], minlen[i + 1]) + triangle[layer][i];
	return minlen[0];
}