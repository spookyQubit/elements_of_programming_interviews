#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/*
Purpose: Given a two dimentional array of shape (n x n), print the elements in a spiral order.
Input:
   1 2 3
   4 5 6
   7 8 9
Output:
1 2 3 6 9 8 7 4 5

Input:
   1   2  3  4
   5   6  7  8
   9  10 11 12
   13 14 15 16
Output:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
*/


void printSpiral(const vector<vector<int> >& m)
{
	int n = m.size();  
	int upper_row = 0;
	int lower_row = n - 1;
	int left_column = 0;
	int right_column = n - 1;

	bool printing = true;

    while(printing){
    	printing = false;
    	for(int i = left_column; i <= right_column; ++i)
    	{
    		printing = true;
    		cout << m[upper_row][i] << endl;
    	}
    	++upper_row;

    	for(int i = upper_row; i <= lower_row; ++i)
    	{
    		printing = true;
    		cout << m[i][right_column] << endl;
    	}
    	--right_column;

    	for(int i = right_column; i >= left_column; --i)
    	{
    		printing = true;
    		cout << m[lower_row][i] << endl;
    	}
    	--lower_row;

    	for(int i = lower_row; i>= upper_row; --i)
    	{
    		printing = true;
    		cout << m[i][left_column] << endl;
    	}
    	++left_column;
    }
}

int main()
{
	vector<vector<int> > m1 = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	//printSpiral(m1);

	vector<vector<int> > m2 = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };
	printSpiral(m2);

}