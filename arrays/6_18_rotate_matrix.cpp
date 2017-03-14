#include <iostream>
#include <vector>

/*
Purpose: Rotate a square matrix of shape (n x n) by 90 degrees clockwise. 
*/

using namespace std;

void printArray(const std::vector<int>& ar)
{
	for(std::vector<int>::const_iterator iter = ar.begin();
		iter != ar.end();
		++iter)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
}

void print2DArray(const vector<vector<int> >& m)
{
	for(vector<vector<int> >::const_iterator iter = m.begin();
		iter != m.end();
		++iter){
		printArray(*iter);
	} 
}

void rotateMatrixClockwise(vector<vector<int> >* pt_m)
{
	vector<vector<int> >& m = *pt_m;

	int n = m.size(); // Assuming a square matrix

	for(int peel_idx = 0; peel_idx < n/2; ++peel_idx)
	{
		// The shape we are dealing with is ( n - 2 * peel_idx x n - 2 * peel_idx)

		int current_mat_size = n - 2 * peel_idx;
		for(int i = 0; i < current_mat_size - 1; ++i)
		{
			int temp1 = m[peel_idx + i][n - 1 - peel_idx];
			m[peel_idx + i][n - 1 - peel_idx] = m[peel_idx][peel_idx + i];

			int temp2 = m[n - 1 - peel_idx][n - 1 - peel_idx - i];
			m[n - 1 - peel_idx][n - 1 - peel_idx - i] = temp1;

			int temp3 = m[n - 1 - peel_idx - i][peel_idx];
			m[n - 1 - peel_idx - i][peel_idx] = temp2;

			m[peel_idx][peel_idx + i] = temp3;

			print2DArray(m);


			//m[peel_idx][peel_idx + i]                 --> m[peel_idx + i][n - 1 - peel_idx]
			//m[peel_idx + i][n - 1 - peel_idx]         --> m[n - 1 - peel_idx][n - 1 - peel_idx - i]
			//m[n - 1 - peel_idx][n - 1 - peel_idx - i] --> m[n - 1 - peel_idx - i][peel_idx]
			//m[n - 1 - peel_idx - i][peel_idx]         --> m[peel_idx][peel_idx + i]
		}
	}
}

int main()
{
	vector<vector<int> > m = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	rotateMatrixClockwise(&m);
}