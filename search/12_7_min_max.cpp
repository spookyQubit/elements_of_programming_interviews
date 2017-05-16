#include <iostream>
#include <vector>

using namespace std;

/*
Purpose: Given an unsorted array, simultaneously find the min and the max.
*/

pair<int, int> get_min_max(const vector<int> &v)
{
	if(v.size() == 0){
		throw length_error("empty");
	}

	if(v.size() == 1){
		return make_pair(v[0], v[0]);

	}

	// v now has atleast 2 elements
	int d_min = min(v[0], v[1]);
	int d_max = max(v[0], v[1]);
	int current_index = 2;
	while(current_index + 1 < v.size()){
		int current_min = min(v[current_index], v[current_index + 1]);
		int current_max = max(v[current_index], v[current_index + 1]);
		d_min = current_min < d_min ? current_min : d_min;
		d_max = current_max > d_max ? current_max : d_max;
		
		current_index = current_index + 2;
	}

	if(current_index < v.size()){
		// this will happen if we have an odd number of elements
		d_min = v[current_index] < d_min ? v[current_index] : d_min;
		d_max = v[current_index] > d_max ? v[current_index] : d_max;
	}

	return make_pair(d_min, d_max);
}



void test1()
{
	vector<int> v = {3, 2, -1, -5, 4, 0};
	pair<int, int> result = get_min_max(v);

	cout << "(" << result.first << ", " << result.second << ")" << endl;
}


int main()
{
	test1();
}