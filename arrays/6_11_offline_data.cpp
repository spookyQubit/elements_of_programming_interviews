#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <assert.h>

/*
Purpose: Given an array of distinct integers, and n < ar.size(), return a subarray
         of size n. Each possible subarrays must be equaly likely.
*/

void printArray(const std::vector<int>& ar)
{
	for(std::vector<int>::const_iterator iter = ar.begin();
		iter != ar.end();
		++iter)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
}

struct Rand{
	Rand();
	int getRand(int min, int max);
};


Rand::Rand()
{
	srand(time(NULL));
}

int Rand::getRand(int min, int max)
{
    //srand(time(NULL)); 
	int range = max - min;
	int random_number = min + std::rand() % range;
	return random_number;
}

void getSubarray(std::vector<int>* pt_ar, int n)
{
	std::vector<int>& ar = *pt_ar;
	
	Rand rand;
	// random number generator 
	for(int i = 0; i < n; ++i)
	{
		int randomNumber = rand.getRand(i, ar.size());
		//std::cout << "randomNumber = " << randomNumber 
        //          << " ar.size() = " << ar.size()  
		//          << std::endl;
		std::swap(ar[i], ar[randomNumber]);
		//printArray(ar);
	}
}


int main()
{
	srand(time(NULL));
    

	std::vector<int> ar = {1, 2, 3, 4};
	int n = 3;
	getSubarray(&ar, n);

	printArray(ar);
}

