#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

/*
Purpose: Find k nearest starts. 
Suppose we are given the distance of N stars from earth. We need to find the distances of k nearest stars. 
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

vector<int> get_k_nearest(const vector<int>& distances, int k)
{
	priority_queue<int> q; // default priority_queue is a max heap

	int current_idx = 0;
	while(current_idx < k && current_idx < distances.size()){
		q.emplace(distances[current_idx++]);
	}

	while(current_idx < distances.size()){
		if(distances[current_idx] < q.top()){
			q.pop();
			q.emplace(distances[current_idx]);
		}
		++current_idx;
	}

	vector<int> k_min;
	while(!q.empty()){
		k_min.emplace_back(q.top());
		q.pop();
	}

	return k_min;
}


void test1()
{
	vector<int> distances = {34, 56, 12, 2, 34, 2, 67, 89, 45, 3, 4, 23, 4};	
	int k = 4;

	vector<int> k_min = get_k_nearest(distances, k);
	print_vector(k_min);
}

int main()
{
	test1();
}