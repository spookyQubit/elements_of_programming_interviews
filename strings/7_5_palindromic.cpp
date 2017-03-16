#include <iostream>

using namespace std;

bool isAlphaNumeric(char c)
{
	if(c >= 'a' && c<= 'z'){
		return true;
	}

	if(c >= 'A' && c<= 'Z'){
		return true;
	}

	if(c >= '0' && c<= '9'){
		return true;
	}

	return false;
}

bool isPalindrome(char c[], int s)
{
	for(int i = 0, j = s - 1; i < j; )
	{
		if(!isAlphaNumeric(c[i])){
			++i;
			continue;
		}
		if(!isAlphaNumeric(c[j])){
			--j;
			continue;
		}

		// c[i] and c[j] are both alpha numeric
		if(c[i] != c[j]){
			return false;
		}

		++i;
		--j;
	}

	return true;
}

int main()
{
	char c[] = {'i', 'i', ' '};
	int s = 2;
	cout << isPalindrome(c, s) << endl; 
}