#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
Purpose: Given an array, find the longest subarray with distinct elements. 
*/

pair<int, int> get_longest_subarray_with_distinct_elements(const vector<char> &v)
{
	pair<int, int> result = make_pair(-1, -1);
	int max_distance = 0;

	unordered_map<char, int> element_position_in_current_longest_subarray;
	int l = 0;
	int r = 0;

	while(l < v.size())
	{
		while(r<v.size() 
			&& 
			element_position_in_current_longest_subarray.find(v[r]) == 
				element_position_in_current_longest_subarray.end())
		{
			element_position_in_current_longest_subarray.emplace(v[r], r);
			++r;
		}

		if(r - 1 - l > max_distance){
			max_distance = r- 1 - l;
			result.first = l; 
			result.second = r - 1;
		}

		if(r >= v.size()){
			break;
		}else{
			element_position_in_current_longest_subarray.erase(v[r]);
			l = r;
		}
	}

	return result;
}

void test1()
{
	vector<char> v = {'f', 's', 'f', 'e', 't', 'w', 'e', 'n', 'w', 'e'};
	pair<int, int> result = get_longest_subarray_with_distinct_elements(v);

	cout << "(" << result.first << ", " << result.second << ")" << endl;
}

int main()
{
	test1();
}