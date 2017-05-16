#include <iostream>

using namespace std;

/*
Purpose: Given an integer n, find the integer z such that:
         z^2 <= n and (z+1)^2 > n 
*/

int get_integer_square_root(int n)
{
	int l = 1;
	int r = n;

	int result = 1;
	while(l <= r){
		int mid = l + (r - l)/2;

		if(mid*mid > n){
			r = mid - 1;
		}
		else{
			result = mid;
			l = mid + 1;
		}
	}

	return result;
}

void test1()
{
	int n = 8;
	cout << "The integer square root of " 
	     << n
	     << " is " 
	     << get_integer_square_root(n)
	     << endl; 
}

int main()
{
	test1();
	
}
