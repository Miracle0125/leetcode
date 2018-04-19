#include<unordered_map>
#include<vector>
using namespace std;


/*

�ؼ���Ϊ�ؼ��ʵȳ��������趨һ������ѭ��������map������һ��map��ų��ֵĹؼ���
��һ��map��¼����ѭ���г��ֹ��Ĺؼ��ʴ�����
������ڴʵ��йؼ��ʳ��ִ�����������ѭ����һ��ѭ������ַ�������������ѭ���Թؼ��ʳ���Ϊ��λ����

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