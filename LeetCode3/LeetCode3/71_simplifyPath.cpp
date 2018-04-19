#include<vector>
#include<string>
#include<sstream>
using namespace std;


//不明白linux  的文件路径怎么工作的，   这题没法做




string simplifyPath(string path) {
	string res, tmp;
	vector<string> stk;
	stringstream ss(path);
	while (getline(ss, tmp, '/')) {
		if (tmp == "" || tmp == ".") continue;
		if (tmp == ".." && !stk.empty()) stk.pop_back();
		else if (tmp != "..") stk.push_back(tmp);
	}
	for (auto str : stk) res += "/" + str;
	return res.empty() ? "/" : res;
}
