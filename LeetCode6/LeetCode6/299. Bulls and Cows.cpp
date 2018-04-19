
#include"common.h"
#include<map>
#include<set>
#include<sstream>
using namespace std;




string getHint(string secret, string guess) {
	int b = 0, a = b;
	vector<int> cow(10), bull(10), v(10);
	for (auto i : secret) v[i-48]++;
	for (auto i : guess) if (v[i - 48]) { cow[i - 48]++; v[i - 48]--; }
	for (int i = 0; i < secret.size(); i++)
		if (secret[i] == guess[i])  { bull[secret[i]-48]++; cow[secret[i] - 48]--; };
	for (auto i : cow)  b += i;
	for (auto i : bull) a += i;
	return itoa(a) + "A" + itoa(b) + "B";
}


//string getHint(string secret, string guess) {
//	int aCnt = 0;
//	int bCnt = 0;
//	vector<int> sVec(10, 0); // 0 ~ 9 for secret
//	vector<int> gVec(10, 0); // 0 ~ 9 for guess 
//	if (secret.size() != guess.size() || secret.empty()) { return "0A0B"; }
//	for (int i = 0; i < secret.size(); ++i) {
//		char c1 = secret[i]; char c2 = guess[i];
//		if (c1 == c2) {
//			++aCnt;
//		}
//		else {
//			++sVec[c1 - '0'];
//			++gVec[c2 - '0'];
//		}
//	}
//	// count b 
//	for (int i = 0; i < sVec.size(); ++i) {
//		bCnt += min(sVec[i], gVec[i]);
//	}
//	return to_string(aCnt) + 'A' + to_string(bCnt) + 'B';
//}