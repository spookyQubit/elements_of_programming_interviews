#include <iostream>
#include <string>

using namespace std;


/*
Purpose: Given a string: aacccdaaa, compress it to be written in: 2a3c1d3a
Not needed to do in place. 
Assume the string does not include any digits.
*/


string getRunLengthEncoding(const string& s)
{
	string result;
	int index_to_insert = 0;
	char prev_char = s[0];
	int current_char_count = 0; 
	for(int i = 0; i < s.size(); ++i)
	{
		if(s[i] == prev_char){
			++current_char_count;
			continue;
		}
		else{
			result = result + to_string(current_char_count) + prev_char;
			prev_char = s[i];
			current_char_count = 1;
		}
	}

	result = result + to_string(current_char_count) + prev_char;
	return result;
}

string getRunLengthDecoding(const string& s)
{
	string result;
	for(int i = 0; i < s.size(); ++i)
	{
		int count = 0;
		while(s[i] - '0' >= 0 && s[i] - '0' <= 9 && i < s.size())
		{
			count = count * 10 + s[i] - '0';
			++i;
		}

		for(int j = 0; j < count; ++j)
		{
			result = result + s[i];
		}
	}

	return result;
}

int main()
{
	string s = "aacccdaaaaaaaaaaaa";
	string encoded = getRunLengthEncoding(s);
	string decoded = getRunLengthDecoding(encoded);
    
    cout << "s = " << s
    << " encoded = " << encoded
    << " decoded = " << decoded
    << endl; 





}


