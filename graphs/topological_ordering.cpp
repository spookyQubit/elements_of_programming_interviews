#include <unordered_map>
#include <unordered_set>

using namespace std;
/*
Purpose: Given a Directed Acyclic Graph, find its topological ordering.
         Note that this ordering may not be unique.
*/

const string STOP = "-";

void topological_ordering(const unordered_multimap<string, string>& graph)
{
	// The first thing we want to do is to find:
	// Given a 
}

void test1()
{
	/*   f<---a    c--->e
	          |    ^
	          |    |
	          v    |
	          b---->d--->g
	*/

	unordered_multimap<string, string> graph;
	graph.emplace("b", "d");
	graph.emplace("a", "b");
	graph.emplace("a", "f");
	graph.emplace("f", STOP);
	graph.emplace("d", "c");
	graph.emplace("d", "g");
	graph.emplace("c", "e");
	graph.emplace("e", STOP); // "-" is a stopper
	graph.emplace("g", STOP); // "-" is a stopper

	topological_ordering(graph);

}

int main()
{
	test1();
}
