
#include<string>
#include<iostream>
#include<vector>
#include<sstream>
#include<map>
using namespace std;

string fractionToDecimal(int64_t  a, int64_t  b) {

	string ret;
	if (a == 0) return "0";
	if (a < 0) {
		a = -a;
		ret += "-";
	}
	if (b < 0) {
		b = -b;
		ret += "-";
	}
	if (ret.length() == 2) ret = "";


	vector<int64_t> map{ (a%b)*10};

	ret += to_string(a / b) + (a%b == 0 ? "" : ".");
	int repeat_begin = 0, len = 0, i, n;
	for (a = (a%b) * 10; a; a = n)
	{
		n = (a%b) * 10;
		ret += to_string(a / b);
		vector<int64_t>::iterator it = find(map.begin(), map.end(), n);
		if (it != map.end()) {
			while (it != map.end()) {
				it++;
				len++;
			}
			ret.insert(ret.length() - len, "(");
			ret.push_back(')');
			break;
		}
		map.push_back(n);
	}
	return ret;
}

/*int main() {
	cout << fractionToDecimal(1, 2147483648);
	return 1;
}	*/	//if (map[i]) {
		//	if (map[i] == ret.length() - 1) {
		//		ret.erase(ret.length() - 1);
		//		ret += ("(" + to_string(a / b) + ")");
		//		break;
		//	}
		//	
		//	if (ret.length() == repeat_begin + len*2) {
		//		ret.erase(repeat_begin + len, len);
		//		ret.insert(repeat_begin, "(");
		//		ret += ")";
		//		break;
		//	}

		//	if (map[i] == repeat_begin + len) {
		//		len++;
		//	}
		//	else {
		//		repeat_begin = map[i];
		//		len = 1;
		//	}


		//}
		//map[i] = ret.length();