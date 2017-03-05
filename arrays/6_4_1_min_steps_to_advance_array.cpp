#include <iostream>
#include <vector>


/*
Purpose: An array is given with v[i] denoting the max num of forward steps one can take from location i.
The objective is to find the minimum number of steps to reach the end.  
*/

std::pair<bool, unsigned int> minStepsToReachTheEnd(const std::vector<unsigned int>& ar)
{
	std::pair<bool, unsigned int> result = std::make_pair(false, 0);
    
    unsigned int maxIdxReachableTillNow = 0;
    unsigned int steps = 0;
    for(unsigned int i = 0; i < ar.size(); ++i)
    {	
    	if( (ar[i] + i) > maxIdxReachableTillNow )
    	{
    		maxIdxReachableTillNow = ar[i] + i;
    		++steps;
    	}

    	if(maxIdxReachableTillNow >= ar.size())
    	{
    		result.first = true;
    		result.second = steps; 
    		break;
    	}
    }
    
	return result;
}

int main()
{
	std::vector<unsigned int> ar = {3, 3, 1, 0, 2, 0, 1};
    std::pair<bool, unsigned int> result = minStepsToReachTheEnd(ar);

    std::cout << "Is reachable = " << result.first
              << " | min steps = " << result.second
              << std::endl;
}