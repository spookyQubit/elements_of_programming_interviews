#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <limits>

using namespace std;

/*
Purpose:
Building heights are given in east-west order. 
if the building to the east is shorter than a building to the west, 
that building will not be able to view the sunset. 

Find the list of buildings which can vew the sunset.

Example: [10, 5, 7, 15, 10,  20, 6] -- > indexes of [20, 6] = [5, 6]
*/


vector<int> get_sunset_view(const vector<int>& heights)
{
	vector<int> indexes;
	int max_height_till_now = numeric_limits<int>::min();

	for(int i=heights.size() - 1; i>=0; --i)
	{
		if(i == heights.size() - 1 || heights[i] > max_height_till_now){
			indexes.push_back(i);
			max_height_till_now = heights[i];
		}
	}

	return indexes;
}

int main()
{
	vector<int> heights = {10, 5, 7, 15, 10,  20, 6}; // from east to west

	vector<int> indexes = get_sunset_view(heights);

	for(int i=0; i<indexes.size(); ++i)
	{
		cout << indexes[i] << " ";
	}
	cout << endl;
}

