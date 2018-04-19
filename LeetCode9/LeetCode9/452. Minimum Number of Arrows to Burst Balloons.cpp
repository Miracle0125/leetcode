


#include"common.h"



int findMinArrowShots(vector<pair<int, int>>& A) {
	sort(A.begin(), A.end(), [](pair<int, int> a, pair<int, int> b) {return a.first < b.first; });
	int r = 0;
	for (auto i = A.begin(), end = A.end(); i != end; r++)
		for (int l = i->first, r = i->second;; l = max(l, i->first), r = min(r, i->second))
			if (++i != end && (i->first >= l && i->first <= r || i->second >= l && i->second <= r)); else break;
	return r;
}