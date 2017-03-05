#include <iostream>
#include <vector>

/* 
Purpose: Multiply two positive integers represented as vectors.
Example: <1, 1> and <1, 1> should result to <1, 2, 1> 
*/

/*
The most important thing to notice is that:
1) To calculate result_rev[2], we need 
                {<num1_rev[0],num1_rev[2]>, 
                 <num1_rev[1],num1_rev[1]> and 
                 <num1_rev[2],num1_rev[0]>}  
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

void reverseArray(std::vector<int>* pt_rev,
	              const std::vector<int>& ar)
{
	for(int i = ar.size() - 1; i >= 0; --i)
	{
		pt_rev->push_back(ar[i]);
	}
}

void multiplyNums(std::vector<int>* pt_result,
	              const std::vector<int>& num1,
	              const std::vector<int>& num2)
{
	std::vector<int>& result = *pt_result;
	std::vector<int> result_rev;

	std::vector<int> num1_rev;
	reverseArray(&num1_rev, num1);

	std::vector<int> num2_rev;
    reverseArray(&num2_rev, num2);

	int remainder = 0;
	for(int i = 0; 
		i < num1_rev.size() + num2_rev.size();
		++i)
	{
		int k = 0;
		for(int id1 = 0; id1 <= i; ++id1)
		{
			k += num1_rev[id1] * num2_rev[i - id1]; 
		}

		result_rev.push_back((k + remainder) % 10);
		remainder = (k + remainder) / 10;
	}

	if(remainder != 0)
	{
		result_rev.push_back(remainder);
	}

	if(result_rev.back() == 0)
	{
		result_rev.pop_back();
	}

	reverseArray(&result, result_rev);
}


int main()
{
	std::vector<int> num1 = {1, 2};
	std::vector<int> num2 = {3, 5, 6};
	std::vector<int> result;

	multiplyNums(&result, num1, num2);

	printArray(result);
}