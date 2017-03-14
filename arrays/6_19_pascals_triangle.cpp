#include <iostream>
#include <vector>

using namespace std;

/*
Purpose: Generate palcals triangle
*/

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

void generatePascalsTriangle(vector<vector<int> >* pt_m, int height)
{
	vector<vector<int> >& m = *pt_m;

	for(int row_number = 0; row_number < height; ++row_number)
	{
		int number_of_enelemts_in_this_row = row_number + 1; // row_number is zero based
		std::vector<int> v;
		for(int i = 0; i < number_of_enelemts_in_this_row; ++i)
		{
			if(i == 0 || i == number_of_enelemts_in_this_row - 1){
				v.push_back(1);
				continue;
			}

			int temp = m[row_number - 1][i - 1] + m[row_number - 1][i];
			v.push_back(temp);
		}
		m.push_back(v);
	}
}
int main()
{
	vector<vector<int> > m;
	int height = 7; 
	generatePascalsTriangle(&m, height);
	print2DArray(m);
}