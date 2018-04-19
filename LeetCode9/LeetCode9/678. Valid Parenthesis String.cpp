
#include"common.h"
#include<stack>
#include<list>
bool checkValidString(string s) {
	list<int> p, q;
	for (int i = 0; i < s.size(); i++)
	{
		char c = s[i];
		if (c == '(') p.push_back(i);
		else if (c == ')') {
			if (!p.empty())p.pop_back();
			else if (!q.empty())q.pop_front();
			else return false;
		}
		else q.push_back(i);
	}
	for (; !p.empty() && !q.empty();q.pop_front()) {
		if (p.front() < q.front()) {
			p.pop_front();
		}
	}
	return p.empty();
}


//crazy
bool checkValidString2(string s) {
	int lower = 0, upper = 0;
	for (char c : s) {
		if (c == '(') {
			lower++;
			upper++;
		}
		else if (c == ')') {
			lower--;
			upper--;
		}
		else { // * encountered
			lower--;
			upper++;
		}
		lower = max(lower, 0);
		if (upper<0) // unmatched ')' found in the middle of string
			return false;
	}
	return lower == 0;
}

//bool checkValidString(string s) {
//	int n = s.size(), x = 0, y =-1, z = 0;
//	//vector<int> p(s.size()), q(s.size());
//	vector<int> p, q;
//	for (int i = 0; i < s.size(); i++)
//	{
//		char c = s[i];
//		if (c == '(') {
//			p.push_back(i);
//			x++;
//		}
//		else if (c == ')') {
//			if (x) { p.erase(p.end() - 1); x--; }
//			else if (y >= z)z++;
//			else return false;
//		}
//		else {
//			q.push_back(i);
//			y++;
//		}
//	}
//	int i = 0;
//	for (; i<x && y>=z;z++) {
//		if (p[i]<q[z]) 
//			i++;
//	}
//	return x == i;
//}


