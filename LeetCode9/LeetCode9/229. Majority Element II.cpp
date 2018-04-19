

#include"common.h"

/*
���ۣ� n=1/3ʱ 2������Ҫ������һ����Ҫ��
       n=1/4ʱ��3������Ҫ������һ����Ҫ��
	   �Դ�����

*/



//Boyer-Moore Majority Vote algorithm
int Boyer_Moore_Majority(vector<int>& nums) {
	int m;
	int count = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (count == 0) {
			m = nums[i];
			count++;
		}
		else if (nums[i] == m) {
			count++;
		}
		else
			count--;
	}
	return m;
}

vector<int> majorityElement(vector<int>& A) {
	if (A.size() <= 1) 
		return A;
	int num1 = A[0], num2=A[0], c1 = 1, c2 = 0;
	for (auto i = A.begin() + 1; i != A.end(); i++) {
		if (*i == num1) {
			c1++;
		}
		else if (*i == num2) {
			c2++;
		}
		else if (!c1) {
			num1 = *i;
			c1 = 1;
		}
		//���ﱣ֤��2������Ҫ������һ����Ҫ��
		else if (!c2) {
			num2 = *i;
			c2 = 1;
		}
		else {
			//����Ҫ�ĵط�
			c1--;
			c2--;
		}
	}
	vector<int> r;
	c1 = 0;
	c2 = 0;
	for (auto i : A)if (i == num1)c1++; else if(i==num2) c2++;
	if (c1 > A.size() / 3) r.push_back(num1);
	if (c2 > A.size() / 3) r.push_back(num2);
	return r;
}

