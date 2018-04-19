#include<vector>
#include<string>
#include<sstream>
#include<math.h>
using namespace std;

//shit  beats 56%!
int fac(int n){
	int ret = 1;
	for (int i = 1; i <= n; i++)
		ret *= i;
	return ret;
}

vector<int> map, factorial;
stringstream ss;
void impl(int n ,int k) {
	if (n == 2) { 
		if(k==1)
		ss << map[0] * 10 + map[1];
		else ss << map[1] * 10 + map[0];
		return;
	}
	int tmp = factorial[n - 1]; 
	int tmp2 = k%tmp;
	int tmp3 = k / tmp - (!tmp2 ? 1 : 0);
	ss << map[tmp3];
	map.erase(map.begin() + tmp3);
	k =!tmp2?tmp:tmp2;
	impl(n - 1, k);
}

string getPermutation(int n, int k) {
	if (n == 1) return "1";
	int sum=1;
	factorial = vector<int>(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		sum *= i;
		factorial[i]=sum;
	}
	for (int i = 1; i <= n; i++)
		map.push_back(i);
	impl(n, k);
	return ss.str();
}

//int main() {
//string s=	getPermutation(3,5);
//	return 1;
//
//}