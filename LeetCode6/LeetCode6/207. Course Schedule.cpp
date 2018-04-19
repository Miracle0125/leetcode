
#include<vector>
using namespace std;

struct nodes
{
	nodes(int i) :num(i) {};
	int num;
	vector<nodes> to,from;
};
vector<nodes> v;
bool DFS_207(nodes *node) {
	if (node->to.size() == 0) return false;
	bool ret = false;
	for (int i = 0; i < node->to.size(); i++)
	{
		ret |= DFS_207(&node->to[i]);
	}
	return ret;
}

bool canFinish(int n,vector<pair<int,int>> A){
	v=vector<nodes>(n,nodes(-1));
	for (int i = 0; i < A.size(); i++)
	{
		nodes *node = &v[A[i].first];
		node->num = A[i].first;
		node->to.push_back(A[i].second);
		node = &v[A[i].second];
		node->num= A[i].second;
		node->from.push_back(A[i].first);
	}
	for (int i = 0; i < v.size(); i++)
	{
		if(DFS_207(&v[i]));
	}
	return false;
}