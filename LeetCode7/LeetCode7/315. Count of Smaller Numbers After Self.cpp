

#include<vector>
using namespace std;
#include"common.h"


//BS
vector<int> countSmaller(vector<int>& A) {
	int n = A.size(), l, r;
	vector<int> f = vector<int>(A.size());
	if (n) {
		vector<int> v{A[n-1]};
		for (int i = n - 2; i >= 0; i--)
		{
			if (A[i] <= v[0]) v.insert(v.begin(), A[i]);
			else if (A[i] >= v[v.size() - 1]) {
				v.push_back(A[i]);
				f[i] = v.size() - 1;
				for (int j = v.size()-2; j >= 0; j--)
					if (v[j] == A[i]) f[i]--; else break;
			}
			else for (l = 0, r = v.size() - 1; l < r;)
			{
				int mid = (l + r) / 2;
				if (v[mid] >= A[i])
					r = mid;
				else l = mid + 1;
			}
			if (v.size() != n - i) {
				f[i] = r;
				v.insert(v.begin() + l, A[i]);
			}
		}
	}
	return f;
}


//int insert(int val) {
//	TreeNode* left = root, *right = root, *node = new TreeNode(val);
//	if (!root) { root = node; return 0; }
//	if (val >= root->val)
//	{
//		while (root&&root->val < val) {
//			left = root;
//			root = root->right;
//			if (root&&root->val < val) { root->left = left; left->right = nullptr; 
//			}
//			cur++;
//		}
//		left->right = nullptr;
//		node->left = left;
//		node->right = root;
//	}
//	else {
//		cur++;
//		while (root&&root->val >= val) {
//			right = root;
//			root = root->left;
//			if (root&&root->val >= val) { root->right = right; right->left = nullptr; 
//			}
//			cur--;
//		}
//		right->left = nullptr;
//		node->right = right;
//		node->left = root;
//	}
//	root = node;
//	return cur;
//}