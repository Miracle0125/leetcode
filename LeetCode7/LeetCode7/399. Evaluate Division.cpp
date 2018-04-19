



using namespace std;
#include"common.h"
#include<unordered_map>


double dfs(string a,string target, unordered_map<string, vector<pair<string, double>>> &map) {
	if (a == target) return 1;
	if (map[a].size()==0) return -1;
	for (auto i : map[a]) {
		double ret = i.second*dfs(i.first, target, map);
		if (ret > 0) return ret;
	}
	return -1;
}

#define operate(num,mode)(mode?1/num:num)
vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
	unordered_map<string, vector<pair<string,double>>> map;
	for (int i = 0; i < equations.size(); i++)
		map[equations[i].first].push_back( pair<string, double>(equations[i].second, values[i]));
	vector<double> ret;
	for (auto i : queries) {
		string a = i.first, b = i.second;
		if (i.first == i.second) {
			if(map[a].size()==0) ret.push_back(-1);
			else ret.push_back(1); 
			continue;
		}
		int mode = 0;
		if (map[a].size() == 0) { mode++; swap(a, b); }
		ret.push_back(operate(dfs(a, b, map),mode));
	}
	return ret;
}

int main() {
	unordered_map<string, pair<string, double>> map;
	map["fuck"]= pair<string, double>("suck",1);
	auto i = map["a"];
	return 0;


}