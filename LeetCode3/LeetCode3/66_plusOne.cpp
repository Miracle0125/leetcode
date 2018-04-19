#include<vector>
#include"common.h"
#include<iostream>
using namespace std;


void printMatrix(vector<int> &v) {
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
//优解
void plusone2(vector<int> &digits)
{
	int n = digits.size();
	for (int i = n - 1; i >= 0; --i)
		if (digits[i] == 9)
			digits[i] = 0;
		else
			digits[i]++;
			return;
	digits[0] = 1;
	digits.push_back(0);
}

//按照传统加法写的，受影响太大
vector<int> plusOne(vector<int> &A) {
	int n = A.size(),carry=0;
	A[n - 1]++;
	for (int i = n-1; i >= 0; i--)
	{
		A[i] += carry;
		if (A[i]==10) {
			A[i] = 0;
			carry = 1;
		}else{
			carry = 0;
			break;
		}
	}
	if (carry == 1) A.insert(A.begin(), 1);
	//printMatrix(A);
	return A;
}

//int main() {
//	plusOne(vector<int>{1,0,0,0,1});
//}