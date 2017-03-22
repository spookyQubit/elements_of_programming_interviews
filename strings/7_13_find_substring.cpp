#include <iostream>
#include <string>

using namespace std;
/*
Purpose: Given a text t and string s, find the index in t of the first occurance of s.  

RabinCarp: The s can be mapped to a hash value. We can iterate through the text, 
calculating the hash value of the selected string. If the hash matches to the hash of string, 
do an explicit comparison.     
*/

int hashFunction(const string& s)
{
	int h = 0;
	for(int i = 0; i < s.size(); ++i)
	{
		h = 10 * h + (s[i] - '0');
	}

	return h % 31;
}

int RabinCarp(const string& t, const string& s)
{
	int s_length = s.size();
	int s_h = hashFunction(s);

	string sub = t.substr(0, s_length);
	int sub_h = hashFunction(sub);

	for(int i = 0; i < t.size(); ++i)
	{
		if(s_h == sub_h){
			if(sub == s){
				return i;
			}
		}

		sub[0] = "";
		//sub[s_length] 
	}

	return -1;////
}

int main()
{
	string t = "Hi, my name is Shantanu. I am Shantanu";
	string s = "am";

	cout << RabinCarp(t, s) << endl;
}