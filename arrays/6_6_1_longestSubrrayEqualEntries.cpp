#include <iostream>
#include <vector>


int lengthOfLongestSubarrayWithEqualEntries(const std::vector<int>& ar)
{
	int longestTillNow = 0;
	for(int i = 0; i < ar.size(); ++i)
	{
		int currentSubarrayLength = 0;
		for(int j = i; j < ar.size(); ++j)
		{
			if(ar[j] == ar[i]){
				++currentSubarrayLength;
			}
			else{
				i = j-1;
				break;
			}
		}

		if(currentSubarrayLength > longestTillNow){
			longestTillNow = currentSubarrayLength;
		}
	}

	return longestTillNow;
}


int main()
{
	std::vector<int> ar = {1, 2, 3, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3};

	std::cout << lengthOfLongestSubarrayWithEqualEntries(ar) << std::endl;

}