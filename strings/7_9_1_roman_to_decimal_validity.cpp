#include <iostream>
#include <string>
#include <map>

using namespace std;

/*
Purpose: Given a roman string, determine if it is valid or not. 
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
*/

bool checkIfValidLowerValue(int prevDigit, int currentDigit)
{
	if(prevDigit == 5){
		return currentDigit == 5 || currentDigit == 1; 
	}

	if(prevDigit == 10){
		return currentDigit == 10 || currentDigit == 5 || currentDigit == 1;
	}

	if(prevDigit == 100){
		return currentDigit == 100 || currentDigit == 50 || currentDigit == 10;
	}

	if(prevDigit == 500){
		return currentDigit == 500 || currentDigit == 100 || currentDigit == 50;
	}

	if(prevDigit == 1000){
		return currentDigit == 1000 || currentDigit == 500 || currentDigit == 100;
	}
}

bool isValid(string roman, map<char, int> roman_to_decimal)
{
	if(roman.size() == 0){
		return true;
	}

	bool alreadyExceptionIsFound = false;
	int prevDigit = roman_to_decimal[roman[roman.size() - 1]];
	for(int i = roman.size() - 2; i >=0; --i)
	{
		int currentDigit = roman_to_decimal[roman[i]];

		if(currentDigit > prevDigit){
		    alreadyExceptionIsFound = false;		
			continue;
		}
		else if(currentDigit <= prevDigit && alreadyExceptionIsFound == false){
			if(!checkIfValidLowerValue(prevDigit, currentDigit)){
				return false;
			}
			alreadyExceptionIsFound = true;
			continue;
		}
		else if(currentDigit <= prevDigit && alreadyExceptionIsFound == true){
			return false;
		}

		prevDigit = currentDigit;
	}

	return true;
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
	cout << roman << " is " << isValid(roman, roman_to_decimal) << endl;

	roman = "IIXXIV";
	cout << roman << " is " << isValid(roman, roman_to_decimal) << endl;

}