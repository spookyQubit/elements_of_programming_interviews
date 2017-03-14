#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

/*
Purpose: 
Given a string representing a number if base b1, 
convert it into a string representing the same number in base b2. 
2 <= b1, b2 <= 16
Note that extending it to negative integers should be strainghtforward
*/

int convertCharToDigit(const char c)
{
	if(c >= '0' && c <= '9'){
		return c - '0';
	} 
	else if( c >= 'A' && c <= 'F'){
		return c - 'A' +10;
	}

	assert(0); // abort 
}

int getIntInBase10FromStringInGivenBase(const string& s, int b)
{
	int result = 0;
	for(int i = 0; i < s.size(); ++i)
	{
		int current_digit = convertCharToDigit(s[i]);
		result = result * b + current_digit;
	}

	return result;
}

char getChar(int i)
{
    char c = i > 9 ? 'A' + i - 10 : '0' + i;
	return c;
}

string getStringInGivenBaseFromIntInBase10(int a, int b)
{
	string result;
	while(a > 0){
		int current_digit = a % b;
		a = a / b;
		char c = getChar(current_digit);
		result = c + result;
	}
	return result;
}

string baseConvert(const string& s, int b1, int b2)
{
	int input_in_base_10 = getIntInBase10FromStringInGivenBase(s, b1);
	string result = getStringInGivenBaseFromIntInBase10(input_in_base_10, b2);

	return result;
}

int main()
{
	int base1 = 7;
	int base2 = 13; 
	string s = "615";

	string base_converted_string = baseConvert(s, base1, base2);

	cout << base_converted_string << endl;
}