#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/*
Purpose: Given an array of string and a set of words, find the smallest subarray which contain all the words.
*/

pair<int, int> get_smallest_subarray(const vector<string> &a, const unordered_set<string> &words)
{
	pair<int, int> result = make_pair(-1, -1);

	unordered_map<string, int> count_of_words_in_current_subarray;
	// Starting at 0, find the last index in array which contains all the words. 
	int min_distance = a.size() + 1;
	int l = 0;
	int r = 0;
	for( ; l<a.size(); ++l){
		for( ; r<a.size(); ++r)
		{
			if(words.find(a[r]) != words.end()){
				if(count_of_words_in_current_subarray.find(a[r]) != count_of_words_in_current_subarray.end()){
					count_of_words_in_current_subarray[a[r]] += 1;
				}else{
					count_of_words_in_current_subarray.emplace(a[r], 1);
				}
			}

			if(count_of_words_in_current_subarray.size() == words.size()){
				if(r - l < min_distance){
					min_distance = r - l;
					result.first = l;
					result.second = r;
				}
				break;
			}
		}

		if(count_of_words_in_current_subarray.find(a[l]) != count_of_words_in_current_subarray.end()){
			--count_of_words_in_current_subarray[a[l]];
			if(count_of_words_in_current_subarray[a[l]] == 0){
				count_of_words_in_current_subarray.erase(a[l]);
			}
		}
	}
	
	return result;
}

void test1()
{
	vector<string> a = {"apple", "banana", "dog", "pineapple", "orrange", "cat", "mango"};
	unordered_set<string> words = {"banana", "orrange", "blah"};

	pair<int, int> indexes = get_smallest_subarray(a, words);
	cout << "(" << indexes.first << ", " << indexes.second << ")" << endl;
}

int main()
{
	test1();
}
