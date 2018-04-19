

#include"common.h"


//虽然代码写得比较粗糙，但是beats94% 75ms  ，我还是很欣慰的


vector<string> r;
void on_answer_found(char op, int digit, string s) {
	s.push_back(op);
	s+=to_string(digit);
	r.push_back(s);
}

void on_final(string&num, string s, long addition, long multed, int target, int digit) {
	if (addition + digit == target) on_answer_found('+', digit, s);
	if (addition - digit == target) on_answer_found('-', digit, s);
	if (multed*digit + addition - multed == target) on_answer_found('*', digit, s);
}

void dfs(string&num, string s, long addition, long multed, int target, int pos) {
	if (pos == num.size() - 1) {
		on_final(num, s, addition, multed, target, num[pos] - '0');
	}
	else {
		int limit = num[pos] == '0' ? 1 : num.size() - pos;
		for (int len = 1; len <= limit; len++)
		{
			long digit = 0;
			for (int i = pos; i < pos+len; i++)
				digit = digit * 10 + (num[i] - '0');
			if (len == num.size()-pos) on_final(num, s, addition, multed, target, digit);
			else {
				dfs(num, s + "+" + to_string(digit), addition + digit, digit, target, pos+len);

				dfs(num, s + "-" + to_string(digit), addition - digit, -digit, target, pos + len);

				dfs(num, s + "*" + to_string(digit), multed*digit + addition - multed, multed*digit, target, pos + len);
			}
		}
	}
}

vector<string> addOperators(string num, int target) {
	if (num.size() <= 1) {
		if (num.size() == 1 && target == num[0] - '0') return { to_string(target) };
	}
	else {
		int limit = num[0] == '0' ? 1 : num.size() - 0;
		for (int len = 1; len <= limit; len++)
		{
			long digit = 0;
			for (int i = 0; i < len; i++)
				digit =digit*10+ (num[i] - '0');
			if (len == num.size() && digit == target) r.push_back(to_string(digit));
			else {
				dfs(num, to_string(digit), digit, digit, target, len);
			}
		}
	}
	return r;
}

//beats 100% 12ms
class Solution_282 {
	void addOperators(const string& num, long long target, vector<string>& results, string& expr, int len, int pos, long long value) {
		if (pos == (int)num.length()) {
			if (target == value) {
				results.push_back(expr.substr(0, len));
			}
			return;
		}

		int operatorIndex = (pos != 0) ? len++ : -1;
		long long number = 0;

		while (pos < (int)num.length()) {
			int digit = num[pos++] - '0';
			number = number * 10 + digit;
			expr[len++] = digit + '0';

			if (operatorIndex == -1) {
				addOperators(num, target, results, expr, len, pos, number);
			}
			else {
				expr[operatorIndex] = '+';
				addOperators(num, target - value, results, expr, len, pos, number);

				expr[operatorIndex] = '-';
				addOperators(num, target - value, results, expr, len, pos, -number);

				expr[operatorIndex] = '*';
				addOperators(num, target, results, expr, len, pos, value * number);
			}

			if (number == 0) return;
		}
	}
public:
	vector<string> addOperators(string num, int target) {
		string expr(num.length() * 2, '\0');
		vector<string> results;
		addOperators(num, target, results, expr, 0, 0, 0);
		return results;
	}
};