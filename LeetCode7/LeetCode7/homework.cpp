//
//
//
//
//
//using namespace std;
//#include<vector>
//#include<set>
//#include<iostream>
//
//void homework1() {
//	vector<pair<int,int>>ret;
//	set<int> prime{ 2,
//		3,
//		5,
//		7,
//		11,
//		13,
//		17,
//		19,
//		23,
//		29,
//		31,
//		37,
//		41,
//		43,
//		47,
//		53,
//		59,
//		61,
//		67,
//		71,
//		73,
//		79,
//		83,
//		89,
//		97 };
//	for (int i = 6; i <= 100; i+=2)
//		for (int j : prime) 
//			if (prime.find(i - j) != prime.end()) { ret.push_back(pair<int, int>(j, i - j)); break; }
//	int num = 6, count = 1;
//	for (vector<pair<int, int>>::iterator i = ret.begin();i!=ret.end() ;i++,num+=2,count++) {
//		cout << num << "=" << i->first<<"+" << i->second<<" ";
//		if (count % 5==0) cout << endl;
//	}
//}
//
//
//set<int> countPrimes(int n) {
//	set<int> ret;
//	vector<bool> f(n);
//	for (int i = 2; i < n; i++)
//	{
//		if (!f[i]) ret.insert(i);
//		for (int j = 2; i*j<n; j++)
//			f[i*j] = true;
//	}
//	return ret;
//}
//
//void homework2(int n) {
//	vector<char> c;
//	int i = n % 10; n /= 10;
//	for (int bits=1; n>0; i = n % 10, n /= 10,bits++) 
//	{ 
//		c.push_back(i + '0'); 
//		if (bits % 3 == 0) c.push_back(','); 
//	}
//	cout << i;
//	for (int i =c.size()-1; i>=0 ;i--) cout << c[i];
//}
//
//void homework3(int a,int n) {
//	auto prime=countPrimes(a + 50 * n);
//	
//	auto i = ++prime.find(a);
//	for (int j=1; i != prime.end(); i++,j++) {
//		cout << *i<<" ";
//		if (j % 8 == 0) {
//			j = 1;
//			cout << endl;
//		}
//	}
//}
//
////int main() {
////
////	homework3(30000,4);
////	//homework2(236546132);
////	return 0;
////}