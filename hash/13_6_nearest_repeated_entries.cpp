#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>

using namespace std;
/*
Purpose: Find the nearest repeated entries in an array.
*/


pair<string, int> get_nearest_repeated_entries(const vector<string> &v)
{
	unordered_map<string, int> value_last_entry_index;
	
	pair<string, int> result;
	int min_distance_till_now = numeric_limits<int>::max();
	
	for(int i=0; i<v.size(); ++i){
		if(value_last_entry_index.find(v[i]) == value_last_entry_index.end()){
			value_last_entry_index.emplace(v[i], i);
		}else{
			// The string has been encountered before.
			int previous_entry_index = value_last_entry_index[v[i]];
			int distance_from_previos_entry = i - previous_entry_index;
			if(distance_from_previos_entry < min_distance_till_now){
				min_distance_till_now = distance_from_previos_entry;
				result = make_pair(v[i], min_distance_till_now); 
			}
		}
	}

	return result;
}

void test1()
{
	vector<string> v = {"one", "two", "three", "one", "three", "four", "five"};
	pair<string, int> result = get_nearest_repeated_entries(v);

	cout << result.first << " " << result.second << endl;
}

int main()
{
	test1();
}