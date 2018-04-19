




#include"common.h"
#define is_cap(c) (c<'a')
bool detectCapitalUse(string word) {
	if (!word.empty()) {
		int i = 0;
		if (is_cap(word[0]))i++;
		bool head = is_cap(word[i++]);
		for (; i < word.size(); i++)
		{
			if (is_cap(word[i]) != head) return false;
		}
	}
	return true;
}


bool detectCapitalUse2(string word) {
	int cnt = 0;
	for (char c : word) if (isupper(c)) ++cnt;
	return !cnt || cnt == word.size() || cnt == 1 && isupper(word[0]);
}