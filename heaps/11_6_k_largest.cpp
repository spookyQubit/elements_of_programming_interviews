#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;


/*
Purpose: Given a max heap, find the K largest entries.
This assumes that the max heap is implemented as an array.
*/

void print_vector(const vector<int> &v)
{
	for(int i=0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}

	cout << endl;
}


struct HeapNode{
	int index;
	int value;
	HeapNode(int i, int v) : index(i), value(v) {}
};

vector<int> get_k_max_elements(const vector<int>& h, int k)
{
	/*
	Make a structure of candidates, which can potentially be one of the k largest entries. 
	The structure should contain the value as well as the index. 
	The structure should be able to return the max quickly.
	*/

	vector<int> result;

	priority_queue<HeapNode, vector<HeapNode>, function<bool(const HeapNode&, const HeapNode&)> >
	       candidates([](const HeapNode &a, const HeapNode &b){ return a.value < b.value; });

	if(h.size() == 0){
		return result;
	}

	candidates.emplace(HeapNode(0, h[0]));
	int entry_count = 1;
	while(!candidates.empty() && entry_count <= k){
		HeapNode current_max = candidates.top();
		candidates.pop();
		result.emplace_back(current_max.value);

		int l = 2 * current_max.index + 1;
		int r = 2 * current_max.index + 2;

		if(l < h.size()){
			candidates.emplace(l, h[l]);
		}

		if(r < h.size()){
			candidates.emplace(r, h[r]);
		}

		++entry_count;
	}

	return result;
}

void test1()
{
	vector<int> h = {45, 34, 12, 23, 1, 3, 2};
	int k = 3;

	vector<int> result = get_k_max_elements(h, k);
	cout << "The " << k << " max elements are: "; 
	print_vector(result);
	cout << endl;

}

int main()
{
	test1();
}