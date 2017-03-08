#include <iostream>
#include <vector>

/*
Purpose: Remove all duplicate entries of a key from an array. 
Ex: 
    Input:  {1, 2, 3, -1, 0, 1, 2, 5, 1, 1}, 1
    Output: {1, 2, 3, -1, 0, 2, 5} // the last elenets do not matter
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

void removeDuplicates(std::vector<int>* pt_ar, int key)
{
	std::vector<int>& ar = *pt_ar;
	
	int currentIdx = 0; 
	int indexToInsert = 0;

    bool firstKeyAlreadyFound = false;
	while(currentIdx < ar.size()){
		if(!firstKeyAlreadyFound && ar[currentIdx] == key){
			firstKeyAlreadyFound = true;
			++indexToInsert;
		}
		else if(ar[currentIdx] != key){
			ar[indexToInsert] = ar[currentIdx];
			++indexToInsert;
		}
		++currentIdx;
	}
}

int main()
{
    std::vector<int> ar = {1, 2, 3, -1, 0, 1, 2, 5, 1, 1};
    printArray(ar);

    int key = 10; 
    removeDuplicates(&ar, key);
    printArray(ar);
	
}