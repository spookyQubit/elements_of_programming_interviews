#include <iostream>
#include <vector>

/*
Purpose: Given a sorted vecotr of ints, remove all duplicates and return the number of remaining entries. 
         There is no restriction as to what the tailing elements will be.  
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

int removeDuplicates(std::vector<int>* pt_ar)
{
    std::vector<int>& ar = *pt_ar;   

	int id_to_insert = 1; 
	int current_id = 1;
    while(current_id < ar.size())
    {
    	if(ar[current_id] == ar[current_id - 1]){
    		++current_id;
    	}
    	else{
    		ar[id_to_insert] = ar[current_id];
    		//std::swap(ar[id_to_insert], ar[current_id]);
    		++id_to_insert;
    		++current_id;
    	}
    }

    return id_to_insert;
}

int main()
{
	std::vector<int> ar = {2, 3, 5, 5, 7, 11, 11, 11, 13};
        
    printArray(ar);
    int uniqueElements = removeDuplicates(&ar);	
    printArray(ar);
    std::cout << "unique elements = " 
              << uniqueElements
              << std::endl;
}