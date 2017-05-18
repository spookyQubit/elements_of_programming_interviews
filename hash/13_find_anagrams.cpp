#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

/*
Purpose: Given a list of strings, return groups of strings which are anagrams.
*/


vector<vector<string> > get_anagrams(const vector<string>& dict)
{
	unordered_map<string, vector<string> > sorted_to_anagrams;

	for(vector<string>::const_iterator iter=dict.begin(); iter!=dict.end(); ++iter)
	{
		string sorted_string(*iter);
		sort(sorted_string.begin(), sorted_string.end());
		sorted_to_anagrams[sorted_string].emplace_back(*iter);
	}


	vector<vector<string> > anagrams;
	for(unordered_map<string, vector<string> >::const_iterator iter=sorted_to_anagrams.begin();
		iter!=sorted_to_anagrams.end(); ++iter)
	{
		if(iter->second.size() > 1	){
			for(int i=0; i<iter->second.size(); ++i)
			{
				cout << iter->second[i] << " ";
			}
			cout << endl;
			anagrams.push_back(iter->second);
		}
	}
	return anagrams;
}


void test1()
{
	vector<string> dict = {"debitcard", "elvis", "silent", 
	                       "badcredit", "lives", "freedom", 
	                       "listen", "levis", "money"};
	vector<vector<string> > anagrams = get_anagrams(dict);
}

int main()
{
	test1();
}