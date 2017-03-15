#include <iostream>
#include <string>

using namespace std;

/*
Purpose:
In excell, the columns are named as: A, B, .. Z, AA, BB, .. AAA
Given a column id say 4, give the corresponding ecxell column id
*/

string getExcellColumnId(int int_column_id)
{
	string result;
	while(int_column_id > 0)
	{
		int_column_id = int_column_id - 1;

		int m = int_column_id % 26;
		int_column_id = int_column_id / 26;

		char c = m + 'A';
		result = c + result;
	}

	return result;
}

int main()
{
	int int_column_id;
	cout << "Enter an integer column id: ";
	cin >> int_column_id;
	cout << getExcellColumnId(int_column_id) << endl;
}