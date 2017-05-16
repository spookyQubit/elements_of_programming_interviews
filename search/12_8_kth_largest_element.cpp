#include <iostream>
#include <vector>

using namespace std;

/*
Purpose: Given an unsorted array of distinct numbers, find the Kth largest entry. 
This can be done using a priority queue with space complexity = O(k) and time complexity = O(n log k).
This can also be done using the pivoting technique of quick sort. 
*/

void print_vector(const vector<int> &v)
{
	for(int i=0; i<v.size(); ++i)
	{
		cout << v[i] << " ";
	}

	cout << endl;
}

int partition_around_pivot(vector<int> *pt_v, int pivot_index, int l, int r)
{
	// Partitions v[l:r] and returns new_pivot such that 
	// v[l:new_pivot - 1] < v[pivot] and
	// v[new_pivot + 1: r] > v[pivot]

	vector<int> &v = *pt_v;

	int new_pivot_index = l;
	int pivot_value = v[pivot_index];
	swap(v[pivot_index], v[r]);
	for(int i=l; i<r; ++i){
		if(v[i] < pivot_value){
			swap(v[i], v[new_pivot_index++]);
		}
	}  

	swap(v[new_pivot_index], v[r]);

	return new_pivot_index;
}


int get_kth_largest(int k, vector<int> v)
{
	int result;

	int l = 0;
	int r = v.size() - 1;

	while(l <= r){
		int pivot_index = l + (r - l)/2;
		int new_pivot_index = partition_around_pivot(&v, pivot_index, 0, v.size() - 1);

		if(new_pivot_index==k){
			return v[new_pivot_index];
		}else if(new_pivot_index > k){
			r = new_pivot_index - 1;
		}else{
			// new_pivot_index < k
			l = new_pivot_index + 1;
		}
	}
}

void test1()
{
	vector<int> v = {3, 2, 1, 5, 4};
	int k = 4;
	cout << "k = " << k << "th largest element is " 
	     << get_kth_largest(k, v)
	     << endl; 
}

int main()
{
	test1();
}