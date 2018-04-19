#include<vector>
#include<algorithm>
using namespace std;

 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

 //better
 vector<Interval> merge(vector<Interval>& A) {
	 if (A.empty()) return vector<Interval>{};
	 //ÉñÆæµÄĞ´·¨
	 sort(A.begin(), A.end(), [](Interval a, Interval b) {return a.start < b.start; });
	 vector<Interval> ret{A[0]};
	 for (int i = 1; i < A.size(); i++)
		 if (A[i].start > ret.back().end) ret.push_back(A[i]);
		 else ret.back().end = max(ret.back().end, A[i].end);
	 return ret;
 }