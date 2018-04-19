#include<vector>
#include<iostream>
using namespace std;


int search(vector<int>& nums, int target) {

	int n = nums.size(),l = 0, r = n - 1,mid;
	// find the index of the smallest value using binary search.
	// Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
	// Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
	while (l < r) {
		mid = (l + r) / 2;
		if (nums[mid] > nums[r]) l = mid + 1;
		else r = mid;
	}
	int p = l;
	l = 0, r = n - 1;
	while (l <= r) {
		//core
		mid = (l + r) / 2;
		int realmid = (mid + p) % n;
		if (nums[realmid] > target) l = mid + 1;
		else if (nums[realmid] < target) r = mid-1;
		else return realmid;
	}
	return -1;
}
int search2(vector<int>& nums, int target) {
	int a = nums[0],p;
	int n = nums.size();
	if (nums[0] > nums[1]) p = 1;
	else if (nums[n - 1] < nums[n - 2]) p = nums[n - 1];
	else {
		int l = 1, r = n - 2, m;
		while (l <= r) {
			m = (l + r) / 2;
			if (nums[m] > nums[m - 1] && nums[m] < nums[m + 1]) p = m;
			else{
				if (nums[m] > nums[0]) l = m + 1;
				//else 
			}
		}
	}
	//vector<int> cache;
	//for (int i = p; i < nums.size(); i++)
	//{
	//	
	//}




	//6,7,8,9,10,11,12,13,14,15,16,0,1,2,3,4,5    p  = 11 = 
//}        int lo=0,hi=n-1;
//        // find the index of the smallest value using binary search.
//        // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
//        // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
//        while(lo<hi){
//            int mid=(lo+hi)/2;
//            if(A[mid]>A[hi]) lo=mid+1;
//            else hi=mid;
//        }
