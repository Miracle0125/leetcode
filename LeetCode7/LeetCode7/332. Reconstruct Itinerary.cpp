
using namespace std;
#include"common.h"
#include<set>
#include<map>
#include<unordered_map>


//排序到底怎么排的，没弄明白吖
void recurse(unordered_map<string, multiset<string>> &graph,string s, vector<string>&v) {
	auto set = &graph[s];
	while (set->size()) {
		auto to = *set->begin();
		v.push_back(*set->begin());
		set->erase(set->begin());
		recurse(graph, to, v);
	}
}

vector<string> findItinerary(vector<pair<string, string>> A) {
	vector<string>v;
	if (A.size()) {
		unordered_map<string, multiset<string>> graph;
		for (auto i : A)
			graph[i.first].insert(i.second);
		v.push_back("JFK");
		recurse(graph, "JFK", v);
	}
	return v;
}

//accepted


//vector<string> findItinerary(vector<pair<string, string>> tickets) {
//	for (auto ticket : tickets)
//		targets[ticket.first].insert(ticket.second);
//	visit("JFK");
//	return vector<string>(route.rbegin(), route.rend());
//}
//
//map<string, multiset<string>> targets;
//vector<string> route;
//
//void visit(string airport) {
//	while (targets[airport].size()) {
//		string next = *targets[airport].begin();
//		targets[airport].erase(targets[airport].begin());
//		visit(next);
//	}
//	route.push_back(airport);
//}