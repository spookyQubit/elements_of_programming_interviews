#include <iostream>
#include <vector>

using namespace std;

/*
Purpose: Given an array with A with A[0] > A[1] and A[n-1] > A[n-2], find the position of a minima.  
*/

int get_minima(const vector<int>& v)
{
	// assuming that we have atleast 4 elements and that v[0] > v[1] and v[n-1] > v[n-2]

	if(v.size() < 4){
		return -1;
	}

	if(v[0] < v[1]){
		return -1;
	}

	if(v[v.size() - 1] < v[v.size() - 2]){
		return -1;
	}

	// Now we are guaranteed to have atleast one minima
	int left = 0;
	int right = v.size() -1;

	while(left <= right){
		int mid = left + (right - left)/2;
		cout << "left = " << left
		     << " right = " << right
		     << " mid = " << mid 
		     << endl;
        
		if(v[mid] < v[mid - 1] && v[mid] > v[mid + 1]){
			// Check if mid is a part of decreasing line
			// the minima must be to the right
			left = mid + 1;
		}
		else if(v[mid] > v[mid - 1] && v[mid] < v[mid + 1]){
			// Check if mid is a part of increasing line
			// The minima must be to the left
			right = mid - 1;
		}else{
			return mid;
		}
	}
}

void test1()
{
	vector<int> v = {100, 90, 70, 60, 50, 75, 78, 40, 50};
	cout << "The index of a minima = " << get_minima(v) << endl;
}

int main()
{
	test1();
}