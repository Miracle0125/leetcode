#include<string>
#include<iostream>
#include<vector>
using namespace std;

void reverseWords(string &s) {
	s.erase(0, s.find_first_not_of(" "));
	s.erase(s.find_last_not_of(" ") + 1);
	int i = 0;
	while (i<s.length()){
		if (s[i] == ' '&&s[i + 1] == ' ')
			s.erase(i, 1);
		else i++;
	}
	int l0 = 0, r0 = 0, l1 = s.length() - 1, r1 = s.length();
	while (r0 <= l1) {
		if (s[r0] != ' ')r0++;
		if (s[l1] != ' ')l1--;
		if (s[r0] == ' '&&s[l1]==' ') {
			string a = s.substr(l0, r0 - l0), b = s.substr(l1 + 1, r1 - l1-1);
			s.replace(l0, a.size(), b);
			s.replace(l1 + 1 - a.size() + b.size(), b.size(), a);
			l0 = r0 = r0 - a.size() + b.size() + 1;
			r1 = l1 - a.size() + b.size();
			l1 = r1 - 1;
		}
	}
	cout << s << endl;
}

void reverseWords2(string &s) {
	s.erase(0, s.find_first_not_of(" "));
	s.erase(s.find_last_not_of(" ") + 1);
	int i = 0;
	while (i<s.length()) {
		if (s[i] == ' '&&s[i + 1] == ' ')
			s.erase(i, 1);
		else i++;
	}
	int l0 = 0, r0 = 0, l1 = s.length() - 1, r1 = s.length();
	while (r0 <= l1) {
		if (s[r0] != ' ')r0++;
		if (s[l1] != ' ')l1--;
		if (s[r0] == ' '&&s[l1] == ' ') {
			string a = s.substr(l0, r0 - l0), b = s.substr(l1 + 1, r1 - l1 - 1);
			s.erase(l1 + 1, r1 - l1 - 1);
			s.erase(l0, r0 - l0);
			s.insert(l0, b);
			s.insert(l1 + 1 - a.size() + b.size(), a);
			l0 = r0 = r0 - a.size() + b.size() + 1;
			r1 = l1 - a.size() + b.size();
			l1 = r1 - 1;
		}
	}
	cout << s << endl;
}

//int main() {
//	vector<string> v = { "   a   b  c d   e  " };
//	for each (auto s in v)
//		{
//			reverseWords2(s);
//		}
//	return 1;
//}