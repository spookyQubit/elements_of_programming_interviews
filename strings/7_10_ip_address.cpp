#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Purpose: Given a string representing ip address from which the "." has been taken out, 
return all valid ip addresses.
*/

void printAllIps(const vector<string>& all_ips)
{
	for(int i = 0; i < all_ips.size(); ++i )
	{
		cout << all_ips[i] << endl;
	}
}

bool isIpPartValid(const string& s)
{
	if(s.size() > 3){
		return false;
	}

	if(s.front() == '0'  && s.size() > 1){
		return false;
	}

	return stoi(s) < 256 && stoi(s) >= 0; 
}

void getAllIps(vector<string>* pt_all_ips, const string& ip)
{
	int max_letters = 3;
	for(int i = 0; i < max_letters, i < ip.size(); ++i)
	{
		string first = ip.substr(0, i+1);
		if(!isIpPartValid(first)){
			continue;
		} 
		for(int j = i+1; j < i + max_letters, j < ip.size(); ++j)
		{
			string second = ip.substr(i+1, j - i);
			if(!isIpPartValid(second)){
				continue;
			}
			for(int k = j+1; k < j + max_letters, k < ip.size(); ++k)
			{
				string third = ip.substr(j+1, k - j);
				if(!isIpPartValid(third)){
					continue;
				} 
				for(int l = k+1; l < k + max_letters, l < ip.size(); ++l)
				{
					string fourth = ip.substr(k+1, ip.size() - l);
					if(!isIpPartValid(fourth)){
						continue;
					}

					string s = first
					+ "." 
					+ second
					+ "."
					+ third
					+ "."
					+ fourth; 

					pt_all_ips->push_back(s);
				}
			}
		}
	}
}

int main()
{
	string ip = "266111";
	vector<string> all_ips;
	getAllIps(&all_ips, ip);

	printAllIps(all_ips);
}
