





#include"common.h"
#include<string>


//这段时间写的最“业务化”的代码
string originalDigits(string s) {
	int memo['z' + 1]{ 0 }, digis[10]{0};
	for (const char&c : s) memo[c]++;
	digis[0] = memo['z'];
	memo['o'] -= digis[0];
	digis[2]= memo['w'];
	memo['o'] -= digis[2];
	memo['t'] -= digis[2];
	digis[4] = memo['u'];
	memo['o'] -= digis[4];
	memo['f'] -= digis[4];
	digis[6] = memo['x'];
	memo['s'] -= digis[6];
	digis[8] = memo['g'];
	memo['t'] -= digis[8];
	digis[1] = memo['o'];
	memo['n'] -= digis[1];
	digis[3] = memo['t'];
	digis[5] = memo['f'];
	digis[7] = memo['s'];
	memo['n'] -= digis[7];
	digis[9] = memo['n'] / 2;
	string ret;
	for (int i = 0; i < 10;i++) {
		for (int j = 0; j < digis[i]; j++)
		{
			char c = i + '0';
			ret.push_back(c);
		}
	}
	return ret;
}