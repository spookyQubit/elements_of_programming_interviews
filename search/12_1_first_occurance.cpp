#include <iostream>
#include <vector>

using namespace std;

/*
Purpose: Given a sorted array, A, and a key, k, find the index of the first occurance of k. 
If k does not occur, return -1. 
*/


int get_first_occurance(const vector<int>& v, int k)
{
	if(v.size() == 0){
		return -1;
	}

	int left = 0;
	int right = v.size() - 1;

	int result = -1;

	while(left <= right){
		int mid = left + (right - left) / 2;
		cout << mid << endl;
		if(k > v[mid]){
			left = mid + 1;
		}
		else if(k == v[mid]){
			right = mid - 1; // <---- Important
			result = mid;
		}
		else{
			// k < v[mid]
			right = mid - 1; 
		}
	}

	return result;
}


void test1()
{
	vector<int> v = {0, 0, 1, 3, 56, 56, 56, 67,67, 89, 90};
	int k = 98;

	cout << "first occurance of k = " << k 
	     << " in array is at position " 
	     << get_first_occurance(v, k)
	     << endl;
}

int main()
{
	test1();
}
