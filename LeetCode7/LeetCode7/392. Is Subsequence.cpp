



#include"common.h"



bool isSubsequence(string s, string t) {
	int index_s = 0, index_t = 0, size_t = t.size(),size_s=s.size();
	if (!size_s) return true;
	while (index_t < size_t) {
		if (t[index_t] == s[index_s]) 
			if (++index_s == size_s) return true;
		index_t++;
	}
	return false;
}