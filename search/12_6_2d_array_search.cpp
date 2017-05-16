#include<iostream>
#include <vector>

using namespace std;

/*
Purpose: Given an increasing matrix, find if a key exists. 
*/

void print_matrix(const vector<vector<int> > &m)
{
	for(int r=0; r<m.size(); ++r)
	{
		const vector<int> &row = m[r];
		for(int col=0; col<row.size(); ++col)
		{
			cout << row[col] << " ";
		}
		cout << endl;
	}
}

pair<int, int> get_shape(const vector<vector<int> > &ar)
{
	if(ar.size() == 0){
		return make_pair<int, int>(0, 0); 
	}

	int rows = ar.size();
	int cols = ar[0].size();

	return make_pair(rows, cols);
}


bool search_2d_array_helper(int k, const vector<vector<int> > &ar, 
	                        int rows_min, int rows_max, 
	                        int cols_min, int cols_max)
{
	cout << "rows_min = " << rows_min
	     << " rows_max = "<< rows_max
	     << " cols_min = " << cols_min
	     << " cols_max = " << cols_max
	     << endl; 

	if(rows_min > rows_max || cols_min > cols_max)
	{
		return false;
	}

	int row_mid = rows_min + (rows_max - rows_min) / 2;
	int col_mid = cols_min + (cols_max - cols_min) / 2;

	cout << "row_mid = " << row_mid
	     << " col_mid = " << col_mid
	     << " ar[row_mid][col_mid] = " << ar[row_mid][col_mid]
	     << endl;   
	if(ar[row_mid][col_mid] == k){

		return true;
	}
	else if(ar[row_mid][col_mid] > k){
		return search_2d_array_helper(k, ar, rows_min, row_mid - 1, cols_min, col_mid - 1);
	}
	else{
		// ar[row_mid][col_mid] < k
		return (search_2d_array_helper(k, ar, row_mid + 1, rows_max, cols_min, cols_max) 
			    ||
			    search_2d_array_helper(k, ar, rows_min, row_mid, col_mid + 1, cols_max));

	}

	return false;
} 

bool search_2d_array(int k, const vector<vector<int> > &ar)
{
	pair<int, int> rows_cols = get_shape(ar);
	cout << "shape = (" << rows_cols.first << ", " << rows_cols.second << ")" << endl;

	int rows_min = 0;
	int rows_max = rows_cols.first;
	int cols_min = 0;
	int cols_max = rows_cols.second;

	return search_2d_array_helper(k, ar, rows_min, rows_max - 1, cols_min, cols_max - 1);
}


void test1()
{
	vector<vector<int> > ar = {{-1, 2, 4, 4, 6}, 
	                           {1, 5, 5, 9, 21}, 
	                           {3, 6, 6, 9, 22}, 
	                           {3, 6, 8, 10, 24}, 
	                           {6, 8, 9, 12, 25}, 
	                           {8, 10, 12, 13, 40}};

	print_matrix(ar);

	int k = -1;
	cout << "k = " << k << " is " << search_2d_array(k, ar) << " present" << endl;
}

int main()
{
	test1();
}