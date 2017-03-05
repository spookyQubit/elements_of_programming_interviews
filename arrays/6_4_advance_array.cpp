#include <iostream>
#include <vector>

/*
Purpose:
An array is given with v[i] denoting the max num of forward steps one can take from location i.
The objective is to find whether one can reach the end.  
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


void getZeroIdxs(std::vector<unsigned int>* pt_zeroIdxs,
	             const std::vector<unsigned int>& ar)
{
	for(unsigned int i = 0; i < ar.size(); ++i)
	{
		if(ar[i] == 0)
		{
			pt_zeroIdxs->push_back(i);
		}
	}
}

void getRangesBetweenZeros(std::vector<std::pair<unsigned int, unsigned int> >* pt_rangesBetweenZeros, 
	                       const std::vector<unsigned int>& zeroIdxs)
{
	unsigned int firstZeroIdx = 0;
	for(unsigned int i = 0; i < zeroIdxs.size(); ++i)
	{
		std::pair<unsigned int, unsigned int> p = std::make_pair(firstZeroIdx, zeroIdxs[i]);
        pt_rangesBetweenZeros->push_back(p); 

        firstZeroIdx = zeroIdxs[i];
	}
}

bool isCurrentRangeSkipable(const std::pair<unsigned int, unsigned int>& rangeBetweenZeros,
	                        const std::vector<unsigned int>& ar)
{
	unsigned int range_begin = rangeBetweenZeros.first;
	unsigned int range_end = rangeBetweenZeros.second;

    for(unsigned int i = range_end - 1; i > range_begin; --i)
    {
    	if(ar[i] > range_end - i)
    	{
    		return true;
    	}
    } 
	return false;
}

bool isEndReachable(const std::vector<unsigned int>& ar)
{
	// ar = <3, 3, 1, 0, 2, 0, 1>

    // zeroIdxs = <3, 5>
	std::vector<unsigned int> zeroIdxs;
	getZeroIdxs(&zeroIdxs, ar);

    // rangesBetweenZeros = < (0,3), (3, 5)>
    std::vector<std::pair<unsigned int, unsigned int> > rangesBetweenZeros;
	getRangesBetweenZeros(&rangesBetweenZeros, zeroIdxs);

	for(unsigned int i = 0; i < rangesBetweenZeros.size(); ++i)
	{
		if(isCurrentRangeSkipable(rangesBetweenZeros[i], ar) == false)
		{
			return false;
		}
	}

	return true; // In case all zeros are passable. 
}


int main()
{
	std::vector<unsigned int> ar = {3, 3, 1, 0, 2, 0, 1};
    //std::vector<unsigned int> ar = {3, 2, 0, 0, 2, 0, 1};

    bool result = isEndReachable(ar);	

    std::cout << "result = " << result << std::endl;
}