#include<vector>
#include<iostream>
using namespace std;

/*

	

*/

void nextPermutation(vector<int>& nums) {
	int k = -1 ,l = -1, len = nums.size();
	for (int i = len-2; i >=0; i--)
	{
		if (nums[i + 1] > nums[i]) {
			k = i;
			break;
		}	
	}
	if (k == -1) {
		reverse(nums.begin(), nums.end());
		return;
	}
	for (int i = len - 1; i >k; i--)
	{
		if (nums[i] > nums[k]) {
			l = i;
			break;
		}
	}
	swap(nums[k], nums[l]); //��֮���ҵ���Сֵ�滻
	reverse(nums.begin() + k + 1, nums.end());//��ΪĿǰK֮���ǵ�������ת������Ϊ������С��
	//for (int i = 0; i < len; i++)
	//{
	//	cout << nums[i] << "  ";
	//}
}

//int main() {
//	int a[] = { 1,2,3 };
//	vector<int> b(a,a+sizeof(a)/4);
//	nextPermutation(b);
//	system("pause");
//}