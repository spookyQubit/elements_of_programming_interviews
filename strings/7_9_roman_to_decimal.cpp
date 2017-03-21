#include <iostream>
#include <string>
#include <map>

using namespace std;

/*
Purpose: Convert Roman to decimal
I -->    1
V -->    5
X -->   10
L -->   50
C -->  100
D -->  500 
M --> 1000

1) The letters must be non-decreasing, except:
a) I can come before V and X
b) X can come before L and C
c) C and come before D and M

2) Two exceptions cannot come consucutively. For example: IIX is not allowed.

Assumption: The input is a valid Roman string.     
*/

int getDecimal(string roman, map<char, int> roman_to_decimal)
{
	if(roman.size() == 0){
		return 0;
	}

	int currentDigit = roman_to_decimal[roman[roman.size() - 1]];
	int result = currentDigit;
	for(int i = roman.size() - 2; i >= 0; --i)
	{
		if(roman_to_decimal[roman[i]] >= currentDigit){
			result += roman_to_decimal[roman[i]]; 
		}
		else{
			result = result - roman_to_decimal[roman[i]]; 
		}

		currentDigit = roman_to_decimal[roman[i]];
	}

	return result;
}

void create_romal_to_decimal_map(map<char, int>* pt_roman_to_decimal)
{
	map<char, int>& roman_to_decimal = *pt_roman_to_decimal;
	roman_to_decimal['I'] = 1;
	roman_to_decimal['V'] = 5;
	roman_to_decimal['X'] = 10;
	roman_to_decimal['L'] = 50;
	roman_to_decimal['C'] = 100;
	roman_to_decimal['D'] = 500;
	roman_to_decimal['M'] = 1000;
}


int main()
{
	map<char, int> roman_to_decimal;
	create_romal_to_decimal_map(&roman_to_decimal);

	string roman = "XXIV";
	cout << getDecimal(roman, roman_to_decimal) << endl;

}