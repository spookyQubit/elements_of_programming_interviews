#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

/*
Purpose:
Given a char*, remove all occurances of 'b' and replace all 'a' with two 'd'. 
*/

int MAX_LENGTH = 20;

void printCharArray(const char cAr[], int s) // how to pass char [] as reference
{
	for(int i = 0; i < s; ++i)
	{
		cout << cAr[i];
	}
	cout << endl;
}

int removeB(char cAr[], int s)
{
	int index_to_insert = 0;
	for(int i = 0; i < s; ++i)
	{
		if(cAr[i] != 'b'){
			swap(cAr[i], cAr[index_to_insert]);
			++index_to_insert;
		}
	}

	return index_to_insert;
}

int getCountOfA(const char cAr[], int s)
{
	int count_a = 0;
	for(int i = 0; i < s; ++i)
	{
		if(cAr[i] == 'a'){
			++count_a;
		}
	}

	return count_a;
}

void addA(char cAr[], int size_after_removing_b, int s)
{
	int index_to_insert = s;
	for(int i = size_after_removing_b; i >=0; --i)
	{
		if(cAr[i] == 'a'){
			cAr[index_to_insert--] = 'd';
			cAr[index_to_insert--] = 'd';
		}
		else{
			cAr[index_to_insert--] = cAr[i];
		}
	}
}

int removeAndReplace(char cAr[], int s)
{
	// 'a' --> 'dd'
	// 'b' --> ''

	int size_after_removing_b = removeB(cAr, s);
	printCharArray(cAr, size_after_removing_b);
    
    int count_a = getCountOfA(cAr, size_after_removing_b);

    int final_size = size_after_removing_b + count_a;
    addA(cAr, size_after_removing_b, final_size);
    
    return final_size;
}

int main()
{
	//char cAr[MAX_LENGTH] = {'a', 'c', 'd', 'a', 'b', 'a', 'r'};
	char cAr[MAX_LENGTH] = {'a', 'b', 'c', 'a'};
	int s = 4;
	
	printCharArray(cAr, s);
	
	int final_size = removeAndReplace(cAr, s);
	printCharArray(cAr, final_size);
}

