



#include"common.h"

//best

void combination(vector<vector<int>> & res, vector<int> solu, int k, int n) {
	if (solu.size() == k && n == 0) res.push_back(solu);
	if (solu.size() < k) {
		for (int i = solu.size() == 0 ? 1 : solu.back() + 1; i <= 9; i++) {
			if (i > n) break;
			solu.push_back(i);
			combination(res, solu, k, n - i);
			solu.pop_back();
		}
	}
}
vector<vector<int>> _combinationSum3(int k, int n) {
	vector<vector<int>> res;
	vector<int> solu;
	combination(res, solu, k, n);
	return res;
}




vector<vector<int>> impl_combinationSum3(int k, int n, int start) {
	vector<vector<int>>r;
	if (k == 1) {
		if (start <= n && n <= 9)
			r.push_back(vector<int>{n});
	}
	else {
		for (int i = start; i <= 9; i++)
		{
			auto v = impl_combinationSum3(k - 1, n - i, i + 1);
			if (!v.empty()) {
				for (auto& sub : v)
					sub.insert(sub.begin(), i);
				r.insert(r.end(), v.begin(), v.end());
			}
		}
	}
	return r;
}


vector<vector<int>>	combinationSum3(int k, int n) {
	return impl_combinationSum3(k, n, 1);
}

//void judge(vector<vector<int>> r,int n) {
//	for (auto v : r) {
//		int sum = 0;
//		for (auto i : v) {
//			sum += i;
//		}
//		if (sum != n) cout << "wrong" << endl;
//	}
//}