
#include<string>
#include<iostream>
#include <cstdlib>    
#include <map>   
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;


int static cmp2(string& x, string& y) {
	int len = min(x.size(), y.size()), i;
	for (i = 0; i < len; i++)
	{
		if (x[i] != y[i]) return x[i] > y[i];
	}
	return x>y;
}

//int static cmp3(int& x, int& y) {
//	int a = 0x8000,b=a;
//	while (x&a != 0)a >> 1;
//	while (y&b != 0)b >> 1;
//	while (a != 0 && b != 0)
//	{
//		int c = (x&a), d = (y&b);
//		if (c != d) return c > d;
//	}
//	return cmp2(x,y);
//}
//直接写x+y>y+x  会自动比较，不用写的....
string largestNumber(vector<int>& A) {
	vector<string> arr;
	for (auto i : A) {
		arr.push_back(to_string(i));
	}
	sort(arr.begin(), arr.end(), cmp2);
	string ret;
	if (A[0]== 0) return "0";
	for (int i = 0; i < A.size(); i++)
		ret += arr[i];
	return ret;
}

string largestNumber2(vector<int> &num) {
	vector<string> arr;
	for (auto i : num)
		arr.push_back(to_string(i));
	sort(begin(arr), end(arr), [](string &s1, string &s2) { return s1 + s2>s2 + s1; });
	string res;
	for (auto s : arr)
		res += s;
	while (res[0] == '0' && res.length()>1)
		res.erase(0, 1);
	return  res;
}

//int main() {
//	int a = 9;
//
//	string ret = largestNumber(vector<int>{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
//});
//	return 0;
//}

//void sortMapByValue(map<string, int>& tMap, vector<pair<string, int> >& tVector)
//{
//	for (map<string, int>::iterator curr = tMap.begin(); curr != tMap.end(); curr++)
//		tVector.push_back(make_pair(curr->first, curr->second));
//
//	sort(tVector.begin(), tVector.end(), cmp);
//}

//double calc_weight(int i) {
//	if (i < 10) return double(i * 11) / 10;
//	double ret = 0.0,tail=(10-0.00000000001)/9.0; int bits = 100;
//	while (bits < i) {
//		bits *= 10;
//	}
//	return i / double(bits / 10)+(tail/bits)*(i-i/10*10);
//}