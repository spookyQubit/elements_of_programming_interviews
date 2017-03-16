#include <iostream>

using namespace std;

/*
Purpose:
Given two arrays which are sorted, merge them to form a single sorted array.
{1, 10, 34, 50}, {5, 6, 7, 20, 40, 50} --> {1, 5, 6, 7, 10, 20, 34, 40, 50, 50}
*/

const int MAX_LEN = 100;

void merge(int a1[], int s1, int a2[], int s2)
{
	int write_idx = s1 + s2 - 1;
	int i = s1 - 1;
	int j = s2 - 1; 
	while(i >= 0 && j >= 0){
		if(a1[i] > a2[j]){
			a1[write_idx--] = a1[i];
			--i;
		}
		else if(a1[i] < a2[j]){
			a1[write_idx--] = a2[j];
			--j;
		}
		else if(a1[i] == a2[j]){
			a1[write_idx--] = a1[i];
			--i;
			a1[write_idx--] = a2[j];
			--j;
		}
	}

	while(i >= 0){
		a1[write_idx--] = a1[i];
		--i;
	}

		while(j >= 0){
		a1[write_idx--] = a2[j];
		--j;
	}
} 

void printCArray(int c[], int s)
{
	for(int i = 0; i < s; ++i)
	{
		cout << c[i]  << " ";
	} 
	cout << endl;
}

int main()
{
	int a1[MAX_LEN] = {1, 10, 34, 50};
	int s1 = 4;

	int a2[MAX_LEN] = {5, 6, 7, 20, 40, 50};
	int s2 = 6;

	merge(a1, s1, a2, s2);
	printCArray(a1, s1 + s2);
}
