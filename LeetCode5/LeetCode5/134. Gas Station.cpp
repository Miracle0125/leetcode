
#include<vector>
using namespace std;


//只打败百分之1...   这代码好差
//If the total number of gas is bigger than the total number of cost. There must be a solution.?

//int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
//	int start(0), total(0), tank(0);
//	//if car fails at 'start', record the next station
//	for (int i = 0; i<gas.size(); i++) if ((tank = tank + gas[i] - cost[i])<0) { start = i + 1; total += tank; tank = 0; }
//	return (total + tank<0) ? -1 : start;
//}

bool check(int index,vector<int> &f) {
	int sum = 0;
	for (int i = 0; i < f.size(); i++)
	{
		sum += f[index++];
		if (sum < 0) return false;
		if (index == f.size()) index = 0;
	}
	return true;
}

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int n = gas.size(),sum=0;
	vector<int> f(n,0);
	for (int i = 0; i < n; i++)
	{
		f[i] = gas[i] - cost[i];
		sum += f[i];
	}
	if (sum < 0) return -1;
	for (int i = 0; i < n; i++)
	{
		if (f[i] >= 0 && check(i, f)) return i;
	}
	return -1;
}