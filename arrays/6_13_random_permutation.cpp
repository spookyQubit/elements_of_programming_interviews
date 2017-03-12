#include <iostream>
#include <vector>
#include <ctime>
#include <assert.h>

using namespace std;

/*
Purpose: Given n, generate a random permutation. 
For example, if n = 3, the possible permutations are: {}
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

struct Rand{
	Rand();
	int getRand(int low, int max);
};

Rand::Rand()
{
	// If we put srand, every time we generate a sequence of random numers, they will be the same!
	// That is, is we set srand, we will get: 
	// {1, 0, 2, 1, 2, 0, 1, 2}
	// {1, 0, 2, 1, 2, 0, 1, 2}  --> exact same sequence as above!
	//srand(time(NULL));
}


int Rand::getRand(int low, int max)
{
	// returns a random int in range [low, max - 1]
	int range = max - low;
	return low + std::rand() % range;
}

vector<int> getRandomPermutation(int n)
{
	// Initialize a permutation vector as <0, 1, 2, 3, .. n>
	vector<int> permutation;
    for(int i = 0; i < n; ++i)
    {
    	permutation.push_back(i);
    }

    // Choose a random element in permutation vector and replace it at the beginning. 
    Rand r;
    for(int index_to_insert = 0; index_to_insert < n; ++index_to_insert)
    {
    	// Get a random number in range [index_to_insert, n - 1]
    	int i = r.getRand(index_to_insert, n);
    	assert(i < n && i >= index_to_insert);
    	std::swap(permutation[i], permutation[index_to_insert]);
    }

    return permutation;
}

int main()
{
	int n = 3;
	//vector<int> random_permutation = getRandomPermutation(n);
	//printArray(random_permutation);

    // Test case
    vector<int> perm1 = {0, 1, 2};
    vector<int> perm2 = {0, 2, 1};
    vector<int> perm3 = {1, 0, 2};
    vector<int> perm4 = {1, 2, 0};
    vector<int> perm5 = {2, 0, 1};
    vector<int> perm6 = {2, 1, 0};
    vector<vector<int> > allPerms = {perm1, 
    	perm2, 
    	perm3,
    	perm4,
    	perm5,
    	perm6
    };
    vector<int> counts = {0, 0, 0, 0, 0, 0};

    int numberOfTrials = 10000;
    while(numberOfTrials > 0){
    	vector<int> random_permutation = getRandomPermutation(n);
    	for(int i = 0;
    		i < allPerms.size();
    		++i)
    	{
    		if(allPerms[i] == random_permutation){
    			++counts[i];
    			break;
    		}

    	}
    	--numberOfTrials;
    }
    printArray(counts);
}