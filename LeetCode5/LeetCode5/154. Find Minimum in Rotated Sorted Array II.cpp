
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//麻烦的是mid与A0相等的情况，难以分辨是在左还是在右，
//试着想象空降在一片沙漠，已知左尽头与右尽头都是沙漠，要找一片绿洲,,
//事实证明，我的代码在数据量非常巨大的情况下有优势

	
vector<int> A = {}; 
	int direction = 0;
	int len, l, r, mid, ret = -1;
	int multiple = 5;
	//程序的思路是“绿洲”的长度大概率大于一定值，则寻找绿洲时步伐大一点大概率不会错过，能提高效率
	int jump_out_duplicate(int multiple, int direction_to_go) {
		direction = 1;
		int times_limit = direction_to_go > 0 ? 2 : 4;
		for (int times = 0, scope = r - l; times < times_limit && scope == r - l; times++, multiple = times >(times_limit - 1) / 2 ? 1 : multiple)
		{
			int addition;
			if (direction_to_go > 0) {
				if (direction_to_go == 1) addition = -1 * multiple;
				else addition = multiple;
			}
			else {//第一次运行
				direction = -direction;
				addition = direction*multiple;
			}
			for (int i = mid; i >=l && i<=r; i += addition)
			{
				if (A[i] != A[0]) {
					if (abs(addition) > 1) {
						if (A[i] > A[0]) {
							for (int j = 0; j < multiple; j++)
								if (A[i + j] < A[0]) return A[i + j];
						}
						else	r = i;
					}
					else if (addition < 0) r = i+1;
					else l = i;
					break;
				}
			}
			if (times == times_limit - 1&&scope==r-l) return A[0];
		}
		return -1;
	}

	int findMin(vector<int>& src) {
		A = src;
		len = A.size(), l = 0, r = len - 1;
		if (A[0] < A[r]||len==1) return A[0];
		if (len == 2) return min(A[0], A[1]);
		while (l <= r) {
			mid = (l + r) / 2;
			if (A[mid] > A[0])
				l = mid + 1;
			else if (A[mid] == A[0]) {    
				int direction_to_go;
				if (direction == 0) direction_to_go = 0;
				else if (direction == -1) direction_to_go = 2;
				else direction_to_go = 1;
				int ret = jump_out_duplicate(multiple, direction_to_go);
				if (ret != -1||ret==-1&&A[0]==-1) return ret;
			}
			else if (A[mid - 1] <= A[mid])
				r = mid;
			else return A[mid];
		}
	}

	int findMin2(vector<int> &num) {
		int lo = 0;
		int hi = num.size() - 1;
		int mid = 0;

		while (lo < hi) {
			mid = lo + (hi - lo) / 2;

			if (num[mid] > num[hi]) {
				lo = mid + 1;
			}
			else if (num[mid] < num[hi]) {
				hi = mid;
			}
			else { // when num[mid] and num[hi] are same
				hi--;
			}
		}
		return num[lo];
	}

//};
//	int main() {
//		vector<int> A;
//		for (int i = 0; i < 3000; i++)
//		{
//			A.push_back(2);
//		}
//		vector<int> B = {4,5,9,13,46,100,122,-100,-20,-1};
//		A.insert(A.begin() + 20, B.begin(),B.end());
//		//vector<int> A =  };
//		findMin(A);
//		findMin2(A);
//		return 0;
//}
//

