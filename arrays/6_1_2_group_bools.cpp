#include <iostream>
#include <vector>

/*
Purpose: Rearrange an bools so that all the flase come before true. 
*/

void printArray(const std::vector<bool>& ar)
{ 
	for(std::vector<bool>::const_iterator iter = ar.begin();
		iter != ar.end();
		++iter)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
}


void groupBools(std::vector<bool>* pt_ar)
{
	std::vector<bool>&  ar = *pt_ar;

	int left = 0; 
	int right = ar.size();

	while(left < right)
	{
		if(ar[left] == false){
			++left;
		}
		else{
			std::swap(ar[left], ar[right - 1]);
			--right;
		}
	}
}


int main()
{
	std::vector<bool> ar = {false, true, false, false, true, true, false, true};
	groupBools(&ar);	
	printArray(ar);
}