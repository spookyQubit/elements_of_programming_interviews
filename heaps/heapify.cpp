#include <iostream>
#include <vector>

using namespace std;

/*
Purpose: Given a vector, heapify it.
1) Write a function whcih heapifies the subtree starting at a given index i. 
2) Start by heapifying the smallest tree, i.e. with the deepest parent. 
*/

void heapify(vector<int> *pt_v, int parent);

void pop(vector<int> *pt_h)
{
	// Given a max heap, remove the top-most entry, heapify it and return. 
	vector <int> &h = *pt_h;

	if(h.size() == 0){
		throw length_error("Empty");
	}
	
	swap(h[0], h[h.size() - 1]);
	h.pop_back();
	heapify(&h, 0);
}

void push(vector<int> *pt_h, int val)
{
	// Given a max heap, add an entry, heapify it and return.
	vector <int> &h = *pt_h;

	h.push_back(val);
	// The parent of this last element is h.size() / 2 -1
	int current_index = h.size() - 1;
	int parent= (current_index - 1) / 2;
	while(parent >= 0)
	{
		if(h[parent] < h[current_index]){
			swap(h[parent], h[current_index]);
		}
		else{
			break;
		}

		current_index = parent;
		parent = (current_index - 1) / 2;
	}

}

void heapify(vector<int> *pt_v, int parent)
{
	vector<int> &v = *pt_v;

	// Heapify the vector *pt_v with the subtree rooted at the parent.
	int left = 2 * parent + 1;
	int right = 2 * parent + 2;

	int largest = parent;
	if(left < v.size() && v[parent] < v[left]){
		largest = left;
	}

	if(right < v.size() && v[largest] < v[right]){
		largest = right;
	}

	if(parent != largest){
		swap(v[parent], v[largest]);

		heapify(&v, largest);
	}
}

void make_max_heap(vector<int>* pt_v)
{
	vector<int> &v = *pt_v;

	for(int i = v.size() / 2 - 1; i >=0; --i)
	{
		heapify(&v, i);
	}
}

template <typename T>
void print_vector(const vector<T>& v)
{
	for(auto iter = v.begin(); iter != v.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;
}

void test1()
{
	vector<int> v = {12, 34, 45, 23, 1, 3, 2};
	make_max_heap(&v);

	print_vector(v); 
	pop(&v);
	print_vector(v);
	push(&v, 50);
	print_vector(v);
}

int main()
{
	test1();
}