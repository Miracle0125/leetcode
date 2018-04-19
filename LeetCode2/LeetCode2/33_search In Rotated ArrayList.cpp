#include<vector>
using namespace std;

/*���ֲ��ҵ�����ϸ�ڵ�����
	l<r   ����ʱL=R Ҫ����l==r=0�����


*/

int search(vector<int>& nums, int t) {
	int l = 0, n= nums.size(),r=n-1,mid;
	if (n) {
		while (l < r) {
			mid = (l + r) / 2;
			if (nums[mid] > nums[r]) l = mid + 1;
			else r = mid;
		}
		int rot = l;
		if (t >= nums[0]&&rot>0) { l = 0, r = rot - 1; }
		else { l = rot, r = n - 1; }
		while (l <= r) {
			mid = (l + r) / 2;
			if (nums[mid] > t) r = mid - 1;
			else if (nums[mid] < t) l = mid + 1;
			else return mid;
		}
	}
	return -1;
}