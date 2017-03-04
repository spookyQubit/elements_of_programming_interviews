#include <iostream>
#include <vector>

/*
Purpose: Increment an arbitrary precision integer represented in a vector by d. 
For example 145 is represented as <1, 4, 5> and the incremented solution should be <1, 4, 6> if d = 1
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

void reverseArray(std::vector<int>* pt_reverse_in_ar, 
	              const std::vector<int>& in_ar)
{
	for(int i = in_ar.size() - 1; i >=0; --i)
	{
		pt_reverse_in_ar->push_back(in_ar[i]);
	}
}

void incrementInteger(std::vector<int>* pt_result,
	                  const std::vector<int>& in_ar,
	                  int d)
{
	std::vector<int>& result = *pt_result;
	std::vector<int> reverse_result;
    
    std::vector<int> reverse_in_ar;
	reverseArray(&reverse_in_ar, in_ar);

 
	int div = 0;
	for(int i = 0; i < reverse_in_ar.size(); ++i)
	{
		int current = div + reverse_in_ar[i] + d;
		int remainder = current % 10;
		div = current / 10;
		d = 0; // Do not add the number after the first time.

		reverse_result.push_back(remainder);
	}

	if(div != 0)
	{
		reverse_result.push_back(div);
	}

	reverseArray(&result, reverse_result);
}

int main()
{
	std::vector<int> ar = {9, 9};
    std::vector<int> result;
    int d = 1;

    incrementInteger(&result, ar, d); 

    printArray(result);
}