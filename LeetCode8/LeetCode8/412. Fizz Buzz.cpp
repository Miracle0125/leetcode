

#include"common.h"
#include<string>
vector<string> fizzBuzz(int n) {
	int rounds = n / 15 + (n % 15);
	vector<string> ret(15 * rounds);
	vector<int> num{ 0,1,3,6,7,10,12,13 }, fizz{ 2,5,8,11 }, buzz{ 4,9 };
	for (int i = 0; i < rounds; i++) {
		int head = i * 15;
		for (const int& k : num) ret[k + head] = to_string(k + head + 1);
		for (const int& k : fizz) ret[k + head] = "Fizz";
		for (const int& k : buzz) ret[k + head] = "Buzz";
		ret[head + 14] = "FizzBuzz";
	}
	ret.erase(ret.begin() + n, ret.end());
	return ret;
}