#include <iostream>
#include <vector>

/*
Purpose: Given a positive number n, find all primes from 1 to n and return an array.
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

std::vector<int> enumeratePrimes(int n)
{
	std::vector<bool> possiblePrimes(n, true);	
	std::vector<int> primeAr;

	for(int i = 2; i < n; ++i)
	{

		if(possiblePrimes[i] == true){
			// i is a prime. 
			primeAr.push_back(i);
		}

        // mark all multiples of i as not prime 
		for(int j = 2*i; j < n; j=j+i)
		{
			possiblePrimes[j] = false;
		}
	}

	return primeAr;
	
}
 


int main()
{
	int n = 100;
	std::vector<int> primeAr = enumeratePrimes(n);

	printArray(primeAr);
}