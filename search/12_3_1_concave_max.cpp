#include <iostream>
#include <vector>

using namespace std;

/*
Purpose: We are given an array which is strictly increasing and then strictly decreasing. 
         Find the max element.
*/

int get_max_element(const vector<int>& v)
{
	if(v.size() == 0){
		throw length_error("empty");
	}

	int l = 0;
	int r = v.size() - 1;

	while(l < r){
		int mid = l + (r - l)/2;

		if(v[mid] < v[mid + 1]){
			l = mid + 1;
		}
		else{
			r = mid;
		}
	}

	// End will happen when l = r
	return v[l];
}

void test1()
{
	vector<int> v = {1, 2, 3, 4, 5, -1, -2, -5};
	cout << "The max element in v = "
	     << get_max_element(v)
	     << endl; 
}

int main()
{
	test1();
}