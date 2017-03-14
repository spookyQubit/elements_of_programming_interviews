#include <iostream>
#include <string>
#include <assert.h>
#include <limits>

using namespace std;

/*
Purpose: Given an string of digits, convert it into an int.
"342" --> 342
// How to check for overflow/underflow
*/

int stringToInt(const string& s)
{
	int result = 0;
	bool is_negative = false;
	for(int i = 0; i < s.size(); ++i)
	{
		if(i == 0 && s[i] == '-'){
			is_negative = true;
			continue;
		}

		assert(s[i] >= '0' && s[i] <= '9');
		int current_digit = s[i] - '0';
		if(    (long int) 10 * result + current_digit > numeric_limits<int>::max()
			|| (long int) 10 * result + current_digit < numeric_limits<int>::min()){

			cout << "overflow/underflow" << endl;
		}
		result = 10 * result + current_digit;
	}
	result = is_negative ? -result : result;

	cout << "Returning " << result << endl;
	return result;
}

int main()
{
	string s;
	cout << "Enter a string: ";
	cin >> s;
	cout << stringToInt(s) << endl; 
}