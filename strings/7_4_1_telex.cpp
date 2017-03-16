#include <iostream>

using namespace std;

/*
Purpose: 
Given a char array, replace punctioation marks with its corresponding names:
'.' --> DOT
'!' --> EXCLAMATION
'?' --> COMMA
*/

const int MAX_LENGTH = 100;
const int DOT_TEXT_LENGTH = 3; 
const int EXCLAMATION_TEXT_LENGTH = 11;
const int COMMA_TEXT_LENGTH = 5;

int get_final_size(char c[], int s)
{
	int final_size = s;
	for( int i = 0; i < s; ++i )
	{
		switch(c[i]){
			case '.':
			final_size = final_size + DOT_TEXT_LENGTH - 1;
			break;
			case '!':
			final_size = final_size + EXCLAMATION_TEXT_LENGTH - 1;
			break;
			case ',':
			final_size = final_size + COMMA_TEXT_LENGTH - 1;
			break;
		}
	}

	return final_size;  
}

int talex(char c[], int s)
{
	int final_size = get_final_size(c, s);
	int write_index = final_size - 1;

	for(int current_idx = s - 1; current_idx >= 0; --current_idx)
	{
		if(c[current_idx] == '.'){
			c[write_index--] = 'T';
			c[write_index--] = 'O';
			c[write_index--] = 'D';
		}
		else if(c[current_idx] == '!'){
			c[write_index--] = 'N';
			c[write_index--] = 'O';
			c[write_index--] = 'I';
			c[write_index--] = 'T';
			c[write_index--] = 'A';
			c[write_index--] = 'M';
			c[write_index--] = 'A';
			c[write_index--] = 'L';
			c[write_index--] = 'C';
			c[write_index--] = 'X';
			c[write_index--] = 'E';
		}
		else if(c[current_idx] == ','){
			c[write_index--] = 'A';
			c[write_index--] = 'M';
			c[write_index--] = 'M';
			c[write_index--] = 'O';
			c[write_index--] = 'C';
		}
		else{
			c[write_index--] = c[current_idx];
		}
	}
	return final_size;
}


void printCArray(char c[], int s)
{
	for(int i = 0; i < s; ++i)
	{
		cout << c[i];
	} 
	cout << endl;
}

int main()
{
	char c[MAX_LENGTH] = {'T', 'h', 'i', 's', ',', 
	' ', 'm', 'y', 
	' ', 'f', 'r', 'i', 'e', 'n', 'd', ',', 
	' ', 'i', 's', 
	' ', 'g', 'r', 'e', 'a', 't', '!'};

	int s = 26;

	int final_size = talex(c, s);
	printCArray(c, final_size);
}