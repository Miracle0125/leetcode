


#include"common.h"
#include<map>
using namespace std;




bool wordPattern(string pattern, string str) {
	vector<string> v = split(str, ' ');
	if (pattern.size() != v.size())return false;
	vector<string> map(26,"");
	for (int i = 0; i < pattern.size(); i++)
	{
		string s = map[pattern[i] - 97];
		if (s != "") {
			if (s != v[i]) return false;
		}else{
			if (find(map.begin(), map.end(), v[i]) == map.end()) map[pattern[i]-97] = v[i];
			else return false;
		}
	}
	return true;
}