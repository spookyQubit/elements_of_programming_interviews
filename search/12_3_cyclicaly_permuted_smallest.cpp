#include <iostream>
#include <vector>

using namespace std;

/*
Purpose: Given a cyclicaly sorted array, find the smallest number.
*/

int get_smallest_in_cyclicaly_sorted_array(const vector<int>& v)
{
	int l = 0;
	int r = v.size() - 1;

	if(v.size() == 0){
		throw length_error("empty");
	}

	while(l < r){

		int mid = l + (r - l)/2;

		if(v[mid] > v[r]){
			// The smallest must be on the right side
			l = mid + 1;
		}else{
			r = mid;
		}
	}

	return v[l];
}


void test1()
{
	vector<int> v = {500, 600, 700, 1, 10, 30, 50, 90};
	cout << "The smallest element in v is " 
	     << get_smallest_in_cyclicaly_sorted_array(v)
	     << endl; 
}


int main()
{
	test1();
}