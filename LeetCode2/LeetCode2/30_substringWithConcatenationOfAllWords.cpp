#include<unordered_map>
#include<vector>
using namespace std;


/*

关键点为关键词等长，所以设定一个二重循环和两个map，其中一个map存放出现的关键字
另一个map记录二级循环中出现过的关键词次数，
如果大于词典中关键词出现次数跳出二级循环。一级循环逐个字符串迭代，二级循环以关键词长度为单位迭代

*/

vector<int> findSubstring(string s, vector<string>& words) {
	vector<int> indices;
	int num = words.size(), len = words[0].length(),j,n = s.length();
	unordered_map<string, int> dict;
	for (string s : words) {
		dict[s]++;
	}
	for (int i = 0; i < n-num*len; i++)
	{
		unordered_map<string, int> seen;
		j = 0;
		for (; j < num; j++) {
			string word = s.substr(i + j*len, len);
			if (dict.find(word)!=dict.end())
			{
				seen[word]++;
				if (seen[word] > dict[word])
					break;
			}
			else break;
		}
		if (j == num) indices.push_back(i);
	}
	return indices;
}

//int main() {
//	//test();
//	findSubstring("sbarfoossasdfoobar", vector<string>{"foo","bar"});
//	system("pause");
//}