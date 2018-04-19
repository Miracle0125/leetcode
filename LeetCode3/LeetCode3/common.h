#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *n) : val(x), next(n) {}
};

bool isValid(vector<int> &l, int pos);
vector<string> getBlank(int n);
void init(vector<string> &v, vector<int>& l, int n);
bool go(int &direct, int &x, int &y, int times);

void printMatrix(vector<vector<int>> &v);
void printMatrix(vector<int> &v);