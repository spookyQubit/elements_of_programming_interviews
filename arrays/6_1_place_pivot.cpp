#include <iostream>
#include <vector>


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

void placePivot(std::vector<int>* pt_ar, int p_id)
{
	std::vector<int>& ar = *pt_ar;
	int pivot = ar[p_id];

	int lesser = 0;
	int equal = 0;
	int unclassified = 0;
	int right = ar.size();

	while(unclassified < right)
	{
		if(ar[unclassified] < pivot){
			std::swap(ar[unclassified], ar[equal]);
			++unclassified;
			++equal;
		}
		else if(ar[unclassified] == pivot){
			++unclassified;
		}
		else if(ar[unclassified] > pivot){
			std::swap(ar[unclassified], ar[right - 1]);
			--right;
		}
	}
}

int main()
{
	std::vector<int> ar = {1, 3, 2, 0, -1, 2, 5, 1};
    int pivot_id = 2;
	placePivot(&ar, pivot_id);	

	printArray(ar);
}