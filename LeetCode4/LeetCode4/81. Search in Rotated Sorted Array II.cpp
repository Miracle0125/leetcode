#include<vector>
using namespace std;

//    2 2 2 0 2 2 2 2 2  �����������м��°��� ���״��������rot=0 ,���п�������͹
bool search(vector<int>& nums, int t) {
	int l = 0, n = nums.size(), r = n - 1, mid,i=INT_MIN;
	if (n) {
		//��һ�󴮴��붼������������һ������������...
		if (n > 2 && nums[0] == nums[n - 1]&&t!=nums[0]) {
			if (t > nums[0]) {
				for (i = n-1; i >=0; i--)
					if (nums[i] > nums[0]) {
						l=i+1;
						break;
					}
			}
			else {
				for (i = 0; i < n; i++)
					if (nums[i] < nums[0]) {
						l = i;
						break;
					}
			}
		}
		if (i == -1 || i == n) return false;
			while (l < r) {
				mid = (l + r) / 2;
				if (nums[mid] > nums[r]) l = mid + 1;
				else r = mid;
			}
			int rot = l;
			if (t >= nums[0] && rot>0) { l = 0, r = rot - 1; }
			else { l = rot, r = n - 1; }
			while (l <= r) {
				mid = (l + r) / 2;
				if (nums[mid] == t) return true;
				else if (nums[mid] < t) l = mid + 1;
				else r = mid - 1;
			}
	}
	return false;
}