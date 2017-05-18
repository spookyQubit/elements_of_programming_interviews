#include <iostream>
#include <unordered_map>

using namespace std;

/*
Purpose: Given text1(letter) and text2(magazine), see if the number of each char which appear in text1 
is lesser than the number of each char in text2.  
*/

unordered_map<char, int> get_char_count(const string &text)
{
	unordered_map<char, int> char_count;
	for(char c : text)
	{
		if(char_count.find(c) == char_count.end()){
			pair<char, int> p = make_pair(c, 1);
			char_count.insert(p);
		}else{
			char_count[c] += 1;
		}
	} 

	for(char c : text){
		cout << "count of " << c << " is " << char_count[c] << endl;
	}

	return char_count;
}


bool is_constructable(const string &letter, const string& magazine)
{
	unordered_map<char, int> char_count_letter = get_char_count(letter);
		
	for(char c : magazine)
	{
		if(char_count_letter.find(c) != char_count_letter.end()){
			char_count_letter[c] = char_count_letter[c] - 1;
			if(char_count_letter[c] == 0){
				char_count_letter.erase(c);
			}
		}
	} 

	return char_count_letter.empty();
}

void test1()
{
	string letter = "this is great";
	string magazine = "greatin sis blah things";

	cout << is_constructable(letter, magazine) << endl;
}

int main()
{
	test1();
}
