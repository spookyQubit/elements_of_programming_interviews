#include <iostream>
#include <vector>
#include <ctime>

/*
Purpose: Given a stream of inputs, mantain a vector of a given size where each input element is equally likely. 
*/


class OnlineData
{
public:
	OnlineData(int k);
	void recieveInput(int);
	void printSubArray() const;
private:
	int d_k;
	int d_callsTillNow;
	std::vector<int> d_subArray;
	int getRand(int min, int max);
};

OnlineData::OnlineData(int k) : d_k(k), d_callsTillNow(0)
{
	srand(time(NULL));
}

int OnlineData::getRand(int min, int max)
{
	int range = max - min;
	return min + std::rand() % range;
}


void OnlineData::recieveInput(int n)
{
	++d_callsTillNow;

	if(d_subArray.size() < d_k){
		d_subArray.push_back(n);
		return;
	}

	// The d_subArray is already full. 
	// The probability of choosing the n is d_k/d_callsTillNow.
	// Removal of an element from the array is with equal probability = 1/d_k. 
    
    bool shouldNBeInserted = getRand(0, d_callsTillNow) <= d_callsTillNow;
    if(shouldNBeInserted){
    	// n should be inserted
    	int r = getRand(0, d_k);
    	d_subArray[r] = n;
    }  
}

void OnlineData::printSubArray() const
{
	for(std::vector<int>::const_iterator iter = d_subArray.begin();
		iter != d_subArray.end();
		++iter)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
}


int main()
{
	std::vector<int> ar = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

	int k = 3;
	OnlineData od(k);

    for(int i = 0; i < ar.size(); ++i)
    {
    	od.recieveInput(ar[i]);
    	od.printSubArray();
    }
}