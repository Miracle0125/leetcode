
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


struct p {
	int min_hp;
	int hp;
};

p compare(p p1,p p2) {
		if (p1.min_hp != p2.min_hp)
			return p1.min_hp < p2.min_hp ? p1 : p2;
		else return p1.hp > p2.hp ? p1 : p2;
}

void print_it(p p1) {
	if (p1.min_hp >= 0) cout << " ";
	cout << p1.min_hp << ",";
	if (p1.hp >= 0) cout << " ";
	cout<< p1.hp << " ";
}

//失败的算法，原因在于从前往后推本身就是错误的，因为递推关系根本就不成立
int calculateMinimumHP(vector<vector<int>>& A) {
	vector<p> f(A[0].size());
	f[0].min_hp= A[0][0] < 0 ? -A[0][0] : 0;
	//if (A.size() == 1 && A[0].size() == 1) return f[0].min_hp + 1;
	f[0].hp = A[0][0];
	//print_it(f[0]);
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < A[0].size(); j++)
		{
			if (j == 0 && i == 0) continue;
			p cur = i==0?f[j-1]:compare(f[j], f[j > 0 ? j - 1 : j]);
			if (cur.hp < 0) {
				f[j].min_hp = cur.min_hp + (A[i][j] < 0 ? -A[i][j] : 0);
			}
			else if (cur.hp + A[i][j] < 0) {
				f[j].min_hp = cur.min_hp + abs(cur.hp + A[i][j]);
			}
			else f[j].min_hp = cur.min_hp;
			f[j].hp=cur.hp+ A[i][j];
			//cout << f[j].min_hp << "," << f[j].hp << " ";
			//print_it(f[j]);
		}
		cout << endl;
	}
	return f[A[0].size() - 1].min_hp+1;
}

//f[][]表示在某个点时，不管之前怎么样，只要到达这个点有这么多生命值就能走到终点
int calculateMinimumHP2(vector<vector<int> > &dungeon) {
	int M = dungeon.size();
	int N = dungeon[0].size();
	// hp[i][j] represents the min hp needed at position (i, j)
	// Add dummy row and column at bottom and right side
	vector<vector<int> > hp(M + 1, vector<int>(N + 1, INT_MAX));
	hp[M][N - 1] = 1;
	hp[M - 1][N] = 1;
	for (int i = M - 1; i >= 0; i--) {
		for (int j = N - 1; j >= 0; j--) {
			int need = min(hp[i + 1][j], hp[i][j + 1]) - dungeon[i][j];
			hp[i][j] = need <= 0 ? 1 : need;
		}
	}
	return hp[0][0];
}

//2D to 1D
int calculateMinimumHP3(vector<vector<int> > &A) {
	int M = A.size();
	int N = A[0].size();
	vector<int> hp(N + 1, INT_MAX);
	hp[N - 1] = A[M - 1][N - 1] >= 0 ? 1 : -A[M - 1][N - 1];
	for (int i = M - 1; i >= 0; i--) {
		for (int j = (i == M - 1 ? N - 2 : N - 1); j >= 0; j--) {
			int need = min(hp[j], hp[j == N - 1 ? j : j + 1]) - A[i][j];
			hp[j] = need <= 0 ? 1 : need;
		}
	}
	return hp[0];
}
//
//int main() {
//	vector<vector<int>> A{ { 1, -3, 3 },{ 0, -2, 0 },{ -3, -3, -3 } };
//	//vector<vector<int>> A{ { -2,-3,3 },{ -5,-10,1 },{ 10,30,-70 } };
//int ret=	calculateMinimumHP2(A);
//	return 0;
//}