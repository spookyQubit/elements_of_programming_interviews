#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

/*
Purpose: Sort an almost sorted array. 
A k sorted array is an array where the position of the 
entries are no more than k away from it should be if the 
array was completely sorted.
For example: [3 -1 2 6 4 5 8] is a 2-sorted array.
*/

template <typename T>
void print_vector(const vector<T>& v)
{
	for(auto iter = v.begin(); iter != v.end(); ++iter)
	{
		cout << " " << *iter;
	}

	cout << endl;
}

void get_sorted(vector<int>* pt_v, int k)
{
	vector<int>& v = *pt_v;
	priority_queue<int, vector<int>, function<bool(int, int)> > q([](int a, int b) { return a > b; });

	int inserted_index = 0;
	while(inserted_index < k && inserted_index < v.size()){
		q.push(v[inserted_index++]);
		cout << q.top() << endl;
	}

	// inserted_index = 2 now
	int sorted_till_index = 0;
	while(sorted_till_index < v.size()){
		v[sorted_till_index++] = q.top();

		q.pop();

		if(inserted_index < v.size()){
			q.emplace(v[inserted_index++]);
		}
	}
}

void test1()
{
	vector<int> v = {3, -1, 2, 6, 4, 5, 8};
	int k = 3;

	get_sorted(&v, k);
	print_vector<int>(v);
}

int main()
{
	test1();
}

