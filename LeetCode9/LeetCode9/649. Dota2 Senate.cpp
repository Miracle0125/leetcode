



#include"common.h"


string predictPartyVictory(string s) {
	int ban1 = 0, ban2 = 0,  r = 0, d = 0;
	for (auto c : s) {
		if (c == 'R') {
			if (ban1)  ban1--; else { ban2++, r++; }
		}
		else {
			if (ban2)  ban2--; else { ban1++, d++; }
		} 
	}
	//r -= ban1, d -= ban2;
	if (abs(ban1 - ban2) > 1) {
		return ban2>ban1 ? "Radiant" : "Dire";
	}
	else return r > d ? "Radiant" : "Dire";
}