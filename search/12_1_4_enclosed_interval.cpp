#include <iostream>
#include <vector>

using namespace std;

/*
Purpose: Given an array A, and key k, find the interval [L, U] 
         where L is the first occurance of k and U is the last occurance of k. 
         If k does not appear in A, return [-1, -1]
*/ 

int get_first_occurance(const vector<int>& v, int k)
{
	int left = 0; 
	int right = v.size() - 1;

	int result = -1;
	if(v.size() == 0){
		return result;
	}

	while(left <=right){
		int mid = left + (right - left)/2;
		if(k > v[mid]){
			left = mid + 1;
		}
		else if(k == v[mid]){
			right = mid - 1;
			result = mid;
		}
		else{
			// k < v[mid]
			right = mid - 1;
		}
	}

	return result;
}

int get_last_occurance(const vector<int>& v, int k)
{
	int left = 0; 
	int right = v.size() - 1;

	int result = -1;
	if(v.size() == 0){
		return result;
	}

	while(left <=right){
		int mid = left + (right - left)/2;
		if(k > v[mid]){
			left = mid + 1;
		}
		else if(k == v[mid]){
			left = mid + 1;
			result = mid;
		}
		else{
			// k < v[mid]
			right = mid - 1;
		}
	}

	return result;
}

pair<int, int> get_enclosed_interval(const vector<int>& v, int k)
{
	int lower = get_first_occurance(v, k);
	int upper = get_last_occurance(v, k);

	pair<int, int> p = make_pair(lower, upper);
	return p;
}


int test1()
{
	vector<int> v = {0, 1, 1, 2, 2, 3, 4};
	int k = 0;
	pair<int, int> interval = get_enclosed_interval(v, k);

	cout << "lower = " << interval.first
	     << " upper = " << interval.second
	     << endl;
}

int main()
{
	test1();
}