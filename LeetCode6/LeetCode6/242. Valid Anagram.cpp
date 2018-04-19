
#include<string>
#include<map>
using namespace std;


bool isAnagram(string s, string t) {
	map<char, int> map;
	for (auto i : s) map[i]++;
	for (auto i : t) map[i]--;
	for (auto i = map.begin(); i !=map.end(); i++)
		if (i->second != 0) return false;
	return true;
}