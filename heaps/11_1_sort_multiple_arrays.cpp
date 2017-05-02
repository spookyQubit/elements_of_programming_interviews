#include <iostream> 
#include <functional>
#include <queue>
#include <assert.h>

using namespace std;

/*
Purpose: Given 3 sorted vectors of ints in ascending order, merge them into one single sorted vector.   
*/

void print_heap(auto h)
{
	while(!h.empty()){
		cout << "printing heap" << endl;
		cout << "h.top().first = " << h.top().first
		     << "h.top().second = " << h.top().second 
		     << endl;
		h.pop();
	}
}


vector<int> get_sorted_vector(const vector<int>& v1, const vector<int>& v2, const vector<int>& v3)
{
	/*
	Make a min heap with the  size of the number of vectors. 
	Push the first elements of the vectors. 
	Pop the heap and insert it to the result vector.
	Push the next element of the vector from which the min was extracted.  
	*/

	priority_queue<pair<int,int>, 
	               vector<pair<int, int> >, 
	               function<bool(pair<int, int>, pair<int, int>)> >
	                 h([](pair<int, int> a, pair<int, int> b){ return a.first > b.first; } );

	// Insert the first elements of the vectors in the heap
	vector<vector<int> > v = {v1, v2, v3};
	for(int i =0; i < v.size(); ++i)
	{
		h.emplace(v[i][0], i);
	}

	vector<int> indexes = {0, 0, 0}; // These are the indexes which are last inserted in h from v1, v2, v3
	vector<int> result; // This will have all the sorted ints
	while(!h.empty()){
		int value = h.top().first;
		int idx = h.top().second;
		h.pop();

		cout << value << endl;

		result.emplace_back(value);
		indexes[idx] += 1;
		if(indexes[idx] >= v[idx].size()){
			// All elements of v[idx] have been put in the heap
			continue;
		}

		h.emplace(v[idx][indexes[idx]], idx);
	}

	return result;
}

void test1()
{
	// By default, the priority queue has the max as the top element and the comparator is:
	// bool com(a, b) { return a < b; }
	// The operations which are allowed are: push()/emplace(), pop(), top().

	/*
	priority_queue<int, vector<int>, function<bool(int, int)> > q([](int a, int b){ return a > b; });
	
	q.emplace(2);
	q.emplace(10);
	q.emplace(1);

	cout << q.top() << endl;
	*/

	//vector<int> v1 = {1, 4, 78, 99, 100};
	//vector<int> v2 = {3, 10, 99};
	//vector<int> v3 = {10, 100};

	vector<int> v1 = {2, 9};
	vector<int> v2 = {1, 4};
	vector<int> v3 = {10, 100};

	get_sorted_vector(v1, v2, v3);

	//assert(result == {1, 2, 4, 9, 10, 100});
}


int main()
{
    test1();	
}