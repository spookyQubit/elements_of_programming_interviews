#include <iostream>
#include <unordered_map>

using namespace std;

/*
Purpose: Given a string, find whether it can be permuted to form a palindorm
*/

bool can_be_made_palindrom(const string &s)
{
	unordered_map<char, int> char_count;
	//int num_of_chars_appearing_twice = 0;
	//int num_of_chars_appearing_once = 0;

	for(char c : s){
		if(char_count.find(c) == char_count.end()){
			pair<char, int> p = make_pair(c, 1); 
			char_count.insert(p);
		}else{
			char_count[c] += 1;
		}
	}

	// If the string is of even length, we cannot have any odd occurances. 
	if(s.size() % 2 == 0){
		for(unordered_map<char, int>::const_iterator iter = char_count.begin(); 
			iter != char_count.end(); 
			++iter)
		{
			if(iter->second % 2 != 0){
				return false;
			}
		}

		return true;
	}

	// If the string is of even odd, we have to have one char occuring odd times and no other
	if(s.size() % 2 != 0){
		bool found_char_with_odd_occurance = false;
		for(unordered_map<char, int>::const_iterator iter = char_count.begin(); 
			iter != char_count.end(); 
			++iter)
		{
			if(iter->second % 2 != 0){
				if(found_char_with_odd_occurance){
					//second occurance of a char with odd occurance
					return false;
				}else{
					found_char_with_odd_occurance = true;
				}
			}
		}

		return true;
	}





	return true;

}

void test1()
{
	string s = "fieldefgd";
	cout << can_be_made_palindrom(s) << endl;
}

int main()
{
	test1();
}