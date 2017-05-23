#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <limits>

using namespace std;

/*
Purpose: Given an array of string and a set of words, find the smallest subarray which contain all the words.
*/

pair<int, int> get_smallest_subarray(const vector<string> &a, const unordered_set<string> &words)
{
	pair<int, int> result = make_pair(-1, -1);

	int min_distance = a.size() + 1;
	unordered_map<string, int> word_counts_in_current_subarray;	
	int l = 0;
	int r = 0;
	while(l < a.size() && r < a.size()){
		while(r<a.size() && word_counts_in_current_subarray.size() < words.size()){
			if(words.find(a[r]) != words.end()){
				if(word_counts_in_current_subarray.find(a[r]) != word_counts_in_current_subarray.end()){
					word_counts_in_current_subarray[a[r]] += 1;
				}else{
					word_counts_in_current_subarray.emplace(a[r], 1);
				}
			}
			++r;
		}

		if(r - l < min_distance && word_counts_in_current_subarray.size() == words.size()){
			min_distance = r - l;
			result.first = l;
			result.second = r - 1;
		}

		cout << "l = " << l << endl;
		if(words.find(a[l]) != words.end()){
			word_counts_in_current_subarray[a[l]] -= 1;
			if(word_counts_in_current_subarray[a[l]] == 0){
				word_counts_in_current_subarray.erase(a[l]);
			}
		}
		++l;
	}
	return result;
}

void test1()
{
	vector<string> a = {"apple", "banana", "dog", "pineapple", "orrange", "cat", "mango"};
	unordered_set<string> words = {"banana", "orrange"};

	pair<int, int> indexes = get_smallest_subarray(a, words);
	cout << "(" << indexes.first << ", " << indexes.second << ")" << endl;
}

int main()
{
	test1();
}
