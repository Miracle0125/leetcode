#include<vector>
#include<algorithm>
using namespace std;


struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> build(vector<int> &A) {
	vector<Interval> ret;
	for (int i = 0; i < A.size(); i+=2)
		ret.push_back(Interval(A[i], A[i + 1]));
	return ret;
}





int find(vector<Interval>& A, int val,bool isLeft) {
	int n = A.size(),l = 0, r = n-1,mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (val < A[mid].start) {
			if (mid - 1>=0) {
				if (val > A[mid - 1].end) return isLeft ? mid : mid-1;
				else r = mid;
			}
			else return 0;
		}else if(val>A[mid].end){
			if (mid + 1 <= n - 1) {
				if (val < A[mid + 1].start) return isLeft ? mid + 1 : mid;
				else  l = mid + 1;
			}
			else return n - 1;
		}
		else return mid;
	}
}

void impl(vector<Interval> &A, Interval newInterval,int l) {
	A[l].start = min(newInterval.start, A[l].start);
	A[l].end = max(newInterval.end, A[l].end);
}

vector<Interval> insert(vector<Interval>& A, Interval newInterval) {


	if (A.empty()) return vector<Interval>{newInterval};
	A.insert(A.end(), newInterval);
	sort(A.begin(), A.end(), [](Interval a, Interval b) {return a.start < b.start; });
	vector<Interval> ret{ A[0] };
	for (int i = 1; i < A.size(); i++)
		if (A[i].start > ret.back().end) ret.push_back(A[i]);
		else ret.back().end = max(ret.back().end, A[i].end);
		return ret;
	//int l = find(A, newInterval.start, true), r = find(A, newInterval.end, false);
	//if (!(l-r)) {
	//	if(A.size()==1) impl(A, newInterval, l);
	//else if (l == 0) {
	//		if (newInterval.end < A[l].start)
	//			A.insert(A.begin(), newInterval);
	//		else impl(A, newInterval, l);
	//	}
	//	else if (l == A.size() - 1) {
	//		if (newInterval.start > A[l].end)
	//			A.insert(A.end(), newInterval);
	//		else impl(A, newInterval, l);
	//	}
	//	else impl(A, newInterval, l);
	//}
	//else {
	//	int start = A[l].start, end = A[r].end;
	//	A.erase(A.begin() + l+1, A.begin() + r);
	//	A[l].start = min(newInterval.start, start);
	//	A[l].end = max(newInterval.end, end);
	//}
	//return A;
}

//
//int main() {
//	//vector<Interval> ret = build(vector<int>{1,2,3,5,6,7,8,10,12,16});
//	vector<Interval> ret = build(vector<int>{1, 5});
//	int i = find(ret, 9, false);
//	insert(ret, Interval(6,8));
//	return 1;
//}