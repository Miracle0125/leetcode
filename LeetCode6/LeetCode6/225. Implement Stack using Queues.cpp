

#include<queue>
using namespace std;

//too easy
class MyStack {

public:
	queue<int> q;
	/** Initialize your data structure here. */
	MyStack() {
		
	}

	void push(int x) {
		q.push(x);
		for (int i = 1; i<q.size(); i++) {
			q.push(q.front());
			q.pop();
		}
	}

	void pop() {
		q.pop();
	}

	int top() {
		return q.front();
	}

	bool empty() {
		return q.empty();
	}
};