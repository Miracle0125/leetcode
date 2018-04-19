

#include"common.h"



//太秀了，想不到啊
int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(heaters.begin(), heaters.end());
		sort(houses.begin(), houses.end());

	int i = 0, res = 0;
	for (int house : houses) {
		while (i < heaters.size() - 1 && heaters[i] + heaters[i + 1] <= house * 2) {
			i++;
		}
		res = max(res, abs(heaters[i] - house));
	}

	return res;
}

//int findRadius(vector<int>& houses, vector<int>& heaters) {
//	sort(heaters.begin(), heaters.end());
//	sort(houses.begin(), houses.end());
//	int r = 0, d = 0, m = houses.size(), n = heaters.size(), i = 0, j = 0;
//	for (int i = 0, j = 0,l,r; i < m&&j < n;)
//	{
//		
//		//r = max(r, abs(houses[i] - heaters[j]));
//		//while (i < m&& abs(houses[i] - heaters[j]) <= r)i++;
//		//j++;
//		//while (i < m) {
//		//	if (abs(houses[i] - heaters[j]) <= r)i++;
//		//	else if (j < n&&houses[i] < heaters[j])j++;
//		//	else break;
//		//}
//	}
//	return r;
//}