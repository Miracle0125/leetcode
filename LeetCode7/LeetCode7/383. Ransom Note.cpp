



using namespace std;
#include"common.h"



bool canConstruct(string ransomNote, string magazine) {
	map<char, int> M;
	for (auto i : magazine) M[i]++;
	for (auto i : ransomNote) if (--M[i] < 0) return false;
	return true;
}