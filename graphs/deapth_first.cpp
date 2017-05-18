#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const string STOP = "-";

/*
Purpose: Construct a graph and do a deapth first traversal of the graph.
*/

void print_graph(const unordered_multimap<string, string> &graph)
{
	for(unordered_map<string, string>::const_iterator iter=graph.begin(); 
		iter!=graph.end(); ++iter)
	{
		//cout << iter->first << "-->" << iter.second << endl;
		cout << iter->first << " --> "  << iter->second << endl;
	}
}


void deapth_first_traversal(const unordered_multimap<string, string> &graph, const string &start)
{
	if(graph.empty()){
		return;
	}

	if(graph.find(start) == graph.end()){
		return;
	}

	unordered_set<string> visited;
	stack<string> s;
	s.push(start);
	while(!s.empty()){
		string current_node = s.top();
		cout << current_node << endl;
		visited.emplace(current_node);
		s.pop();

		// Push all the nodes connecting from current node on top of stack
		pair<unordered_multimap<string, string>::const_iterator, 
		     unordered_multimap<string, string>::const_iterator> range 
		                                                          = graph.equal_range(current_node);
		for(unordered_multimap<string, string>::const_iterator iter=range.first; 
			iter!=range.second; ++iter)
		{
			if(visited.find(iter->second) == visited.end() && iter->second != STOP){
				s.push(iter->second);
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
	          b---->d
	*/

	unordered_multimap<string, string> graph;
	graph.emplace("b", "a");
	graph.emplace("b", "d");
	graph.emplace("a", "b");
	graph.emplace("a", "f");
	graph.emplace("f", STOP);
	graph.emplace("d", "c");
	graph.emplace("c", "e");
	graph.emplace("e", STOP); // "-" is a stopper

	print_graph(graph);

	deapth_first_traversal(graph, "a");
}


int main()
{
	test1();
}