#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

/*
Purpose: Given a directed graph and a starting node, do a breadth first traversal.
*/

const string STOP = "-";

void breadth_first_traversal(const unordered_multimap<string, string> &graph, const string &start)
{
	if(graph.empty()){
		return;
	}

	if(graph.find(start) == graph.end()){
		return;
	}

	queue<string> q;
	unordered_set<string> visited;
	q.emplace(start);
	visited.emplace(start);

	while(!q.empty()){
		string current_vertex = q.front();
		visited.emplace(current_vertex);
		cout << current_vertex << endl;
		q.pop();

		auto range = graph.equal_range(current_vertex);
		for(auto iter=range.first; iter!=range.second; ++iter)
		{
			if(visited.find(iter->second) == visited.end() && iter->second != STOP){
				q.emplace(iter->second);
			}
		}
	}
}


void test1()
{
	/*   f<---a     c--->e
	          |^    ^
	          ||    |
	          v|    |
	          b---->d--->g
	*/

	unordered_multimap<string, string> graph;
	graph.emplace("b", "a");
	graph.emplace("b", "d");
	graph.emplace("a", "b");
	graph.emplace("a", "f");
	graph.emplace("f", STOP);
	graph.emplace("d", "c");
	graph.emplace("d", "g");
	graph.emplace("c", "e");
	graph.emplace("e", STOP); // "-" is a stopper
	graph.emplace("g", STOP); // "-" is a stopper


	breadth_first_traversal(graph, "a");
}


int main()
{
	test1();
}