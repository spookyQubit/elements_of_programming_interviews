#include <iostream>
#include <vector>

using namespace std;

/*
Purpose: Given an array of strings and v vector of words, find the smallest subarray in v such that all words
appear in sequence
*/

pair<int, int> get_smallest_subarray_in_sequence(const vector<string> &a, const vector<string> &words)
{

}

void test1()
{
	vector<string> a = {"apple", "banana", "orrange", "dog", "pineapple", "banana", "cat", "mango"};
	vector<string> words = {"orrange", "banana"};

	pair<int, int> indexes = get_smallest_subarray_in_sequence(a, words);
	cout << "(" << indexes.first << ", " << indexes.second << ")" << endl;
}

int main()
{
	test1();
}