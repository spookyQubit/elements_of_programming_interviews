#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
Purpose: Write a string sinusoidaly. 
Hello World!
 e   _   d
H l o w r !
   l   o

Top row    ---> [1, 5, 9, 13, ..]
Middle row ---> [0, 2, 4, 6, 8, ..]
Bottom row ---> [3, 7, 11, 15, ..]

*/

void writeSinusoidaly(const string& s)
{
	cout << " ";
	for(int top=1; top < s.size(); top=top+4)
	{
		cout << s[top] << "   ";
	}
	cout << endl;

	for(int middle=0; middle < s.size(); middle=middle+2)
	{
		cout << s[middle] << " ";
	}
	cout << endl;

	cout << "   ";
	for(int bottom=3; bottom < s.size(); bottom=bottom+4)
	{
		cout << s[bottom] << "   ";
	}
	cout << endl;


}

int main()
{
	string s = "Hello-World!";
	writeSinusoidaly(s);
}