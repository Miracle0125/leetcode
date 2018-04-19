//#include<bitset>
//#include<vector>
//#include<iostream>
//using namespace std;
//
//		vector<string> A;
//		vector<vector<int[2]>> map;
//		bitset<4096> code(0);
//		int target;
//		void debug(vector<vector<int>> a) {
//			for (int i = 0; i < a.size(); i++)
//			{
//				for (int j = 0; j < a[i].size(); j++)
//				{
//					cout << A[a[i][j]] << " ";
//				}
//				cout << endl;
//			}
//		}
//
//		bool compare(string a, string b) {
//			int flag = 0;
//			for (int i = 0; i < a.size(); i++)
//				if (a[i] != b[i])
//					if (++flag > 1)
//						return false;
//			return flag == 1;
//		}
//
//		void findSimilar(int layer) {
//			vector<int> v;
//			for (int i = 0; i < map[layer - 1].size(); i++)
//				for (int j = 1; j < A.size(); j++)
//					if (!code[j] && compare(A[map[layer - 1][i]], A[j]))
//					{
//						v.push_back(j);
//						code[j] = 1;
//					}
//			if (!v.size() || code[target])return;
//			map.push_back(v);
//			findSimilar(layer + 1);
//		}
//
//
//
//		//int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//		//	A = wordList;
//		//	A.insert(A.begin(), beginWord);
//		//	target = distance(A.begin(), find(A.begin(), A.end(), endWord));
//		//	map = vector<vector<int>>{ { 0 } };
//		//	findSimilar(1);
//		//	debug(map);
//		//	return code[target] ? map.size() + 1 : 0;
//		//}
//		vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//			vector<vector<string>> ret;
//			A = wordList;
//			A.insert(A.begin(), beginWord);
//			target = distance(A.begin(), find(A.begin(), A.end(), endWord));
//			int b[2] = { 1,1 };
//			map = vector<vector<int[2]>>{ {1,1} };
//			findSimilar(1);
//			debug(map);
//			//return code[target] ? map.size() + 1 : 0;
//		}
//
//
