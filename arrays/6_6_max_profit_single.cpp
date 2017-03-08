#include <iostream>
#include <vector>
#include <limits>

int getMaxProfit(const std::vector<int>& ar)
{
	int maxProfit = 0;
	int minTillNow = std::numeric_limits<int>::max();

	for(int i = 0; i < ar.size(); ++i)
	{
		if(ar[i] < minTillNow){
			minTillNow = ar[i];
		}

		int currentProfit = ar[i] - minTillNow;
		if(currentProfit > maxProfit){
			maxProfit = currentProfit;
		}
	}

	return maxProfit;
}


int main()
{
	std::vector<int> ar = {310, 315, 275, 295, 260, 270, 290, 230, 255, 250};

	std::cout << getMaxProfit(ar) << std::endl;
}