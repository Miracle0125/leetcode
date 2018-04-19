#include<vector>
#include<string>
#include<sstream>
using namespace std;


//������linux  ���ļ�·����ô�����ģ�   ����û����




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
