#include <iostream>
#include <queue>

using namespace std;

/*
Purpose: Given 3 sorted vectors of ints in ascending order, merge them into one single sorted vector.   
*/


void test1()
{
	// By default, the priority queue has the max as the top element and the comparator is:
	// bool com(a, b) { return a < b; }
	// The operations which are allowed are: push()/emplace(), pop(), top().


	priority_queue<int> q;

	q.emplace(2);
	q.emplace(10);
	q.emplace(1);

	cout << q.top() << endl;


}


int main()
{
    test1();	
}