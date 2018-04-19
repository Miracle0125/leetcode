#include<string>
#include<algorithm>
using namespace std;

//ÓÅ½â,Ë§£¡
string addBinary2(string a, string b)
{
	string s = "";

	int c = 0, i = a.size() - 1, j = b.size() - 1;
	while (i >= 0 || j >= 0 || c == 1)
	{
		c += i >= 0 ? a[i--] - '0' : 0;
		c += j >= 0 ? b[j--] - '0' : 0;
		s = char(c % 2 + '0') + s;
		c /= 2;
	}

	return s;
}

//me
string addBinary(string a, string b) {
	int m= a.length(),n= b.length(),carry=0;
	string ret(max(m,n),'0');
	if (m > n)
		b.insert(0,string(m-n,'0'));
	else a.insert(0, string(n-m, '0'));
	for (int i = max(m, n)-1; i >=0 ; i--)
	{
		ret[i] = a[i]+b[i]+carry-48;
		if (ret[i] > '1') {
			ret[i]-=2;
			carry = 1;
		}else{
			carry = 0;
		}
	}
	if (carry)ret.insert(ret.begin(), '1');
	return ret;
}


//int main() {
//	addBinary("1111","1111");
//}