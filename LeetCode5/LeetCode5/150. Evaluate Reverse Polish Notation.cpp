#include<vector>
#include<stack>
#include<ctype.h>
using namespace std;


int evalRPN(vector<string>& tokens) {
	stack<int> stack;
	for (string s : tokens)
	{
		if (isdigit(s[0])||s.length()>1&&isdigit(s[1]))
			stack.push(atoi(s.c_str()));
		else {
			int ret=0;
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			if (s== "+")ret= a + b;
			if (s == "-")ret=a-b;
			if (s == "*")ret=a*b;
			if (s == "/")ret=a/b;
			stack.push(ret);
		}
	}
	return stack.empty() ? 0 : stack.top();
}