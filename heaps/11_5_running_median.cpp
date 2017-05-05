#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

/*
Purpose: Given a stream of inputs, find the runnig median. 
1) Make a max heap for the left half
2) Make a minn heap for the right half

Invariant: If there are odd elements, the median will be in the left heap.

Case 1) With the new number included, there are odd number of entries
        Insert the new element in the left heap
        l.top() is the median
Case 2) With the new number included, there are even number of entries
        * If current_element >= current_median
            Insert the new element in the right heap
            Current median = average(left.top() + right.top())
        * If current_element < current_median
            Remove the top of the left heap and place it in the right heap
            Insert the current element in the left heap
            Current median = average(left.top() + right.top()) 
   

*/

void get_running_median(const vector<int>& v) 
{
	// It will be better to have an istream
	int current_median;
	int number_of_entries;
	vector<float> median;

	priority_queue<int, vector<int>, function<bool(int, int)> > l([](int a, int b) {return a<b; });
	priority_queue<int, vector<int>, function<bool(int, int)> > r([](int a, int b) {return a>b; });	

	int i = 0;
	while(i < v.size()){
		if(i%2 == 0){
			// Without the current element, l.size() == r.size()
			l.emplace(v[i]);
			median.emplace_back(l.top());
		}
		else{
			// Without the current element, l.size() = r.size() + 1
			// There are two cases:
			// 1) v[i] > l.top()
			// 2) v[i] < l.top()
			if(v[i] >= l.top()){
				r.emplace(v[i]);
				median.emplace_back((l.top() + r.top())/2.0);
			}
			else{
				int max_left = l.top();
				r.emplace(max_left);
				l.pop();
				l.emplace(v[i]);
				median.emplace_back((l.top() + r.top())/2.0);
			}
		}
		cout << median[i] << " ";
		++i;
	}

	cout << endl;
}

void test1()
{
	vector<int> v = {45, 12, 1, 5, 6, 50, 24, 20, 13, 10, 1};
	get_running_median(v);
}

int main()
{
	test1();
}