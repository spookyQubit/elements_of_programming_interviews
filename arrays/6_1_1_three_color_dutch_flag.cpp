#include <iostream>
#include <vector>


/*
Purpose: Given an array of three colors, group the colors together.
*/

typedef enum {RED, GREEN, BLUE} COLOR;

void printArray(const std::vector<COLOR>& ar)
{ 
	for(std::vector<COLOR>::const_iterator iter = ar.begin();
		iter != ar.end();
		++iter)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
}


void groupColors(std::vector<COLOR>* pt_ar)
{
	std::vector<COLOR>& ar = *pt_ar;

	/*
	We will make four subarrays:
	ar[0, r_id - 1]              <== Contains RED
	ar[0, g_id - 1]              <== Contains GREEN
	ar[unclassified, b_id - 1]   <== Contains unclassified colors
	ar[b_id, ar.size() - 1]      <== Contains BLUE
	*/

	int r_id = 0;
    int g_id = 0;
    int unclassified = 0;
    int b_id = ar.size();

    while(unclassified < b_id)
    {
    	if(ar[unclassified] == RED){
    		std::swap(ar[unclassified], ar[r_id]);
    		++r_id;
    		++unclassified;
    	}
    	else if(ar[unclassified] == GREEN){
    		++unclassified;
    	}
    	else if(ar[unclassified] == BLUE){
    		std::swap(ar[unclassified], ar[b_id - 1]);
    		--b_id;
    	}
    }
}


int main()
{
	std::vector<COLOR> ar = {BLUE, RED, BLUE, RED, RED, BLUE, GREEN, BLUE, GREEN};
    groupColors(&ar);
	printArray(ar);
}


