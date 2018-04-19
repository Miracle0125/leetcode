



#include<vector>
#include<map>
using namespace std;




void moveZeroes(vector<int>& A) {
	for (int i = 0,cap=A.size(); i < cap; i++)
	{
		if (!A[i]) {
			A.push_back(0);
			A.erase(A.begin() + i--);
			cap--;
		}
	}
}