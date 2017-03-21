#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

/*
Purpose: Given a number, get all phone mnemonics.
*/

map<int, vector<string> > dict;

void getMnemonicsHelper(vector<string>* pt_mnemonics, 
	string partial_mnemonic, 
	int digit,
	const vector<int>& number)
{
	if(digit == number.size())
	{
		pt_mnemonics->emplace_back(partial_mnemonic);
		return;
	}

	// digit d
	for(int i = 0; i < dict[number[digit]].size(); ++i)
	{
		getMnemonicsHelper(pt_mnemonics, partial_mnemonic + dict[number[digit]][i], digit+1, number);
	}
}

void getMnemonics(vector<string>* pt_mnemonics, const vector<int> number)
{
	int digit = 0;
	string partial_mnemonic;

	getMnemonicsHelper(pt_mnemonics, partial_mnemonic, digit, number);
}

int main()
{
	vector<int> number = {4, 3};

	vector<string> s1 = {"a", "b"};
	dict.insert(make_pair(1, s1));

	vector<string> s2 = {"c", "d"};
	dict.insert(make_pair(2, s2));

	vector<string> s3 = {"e", "f"};
	dict.insert(make_pair(3, s3));

	vector<string> s4 = {"g", "h", "i"};
	dict.insert(make_pair(4, s4));


	vector<string> mnemonics;
	getMnemonics(&mnemonics, number);

	for(int i =0; i < mnemonics.size(); ++i)
	{
		cout << mnemonics[i] << endl;
	}

}