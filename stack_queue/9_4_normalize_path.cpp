#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/*
Purpose: Take a path name and return the shortest path. 
example: 
path = ./dir1/./../dir2 = dir2
*/


vector<string> get_normalized_path(const vector<string> path)
{
	string curr_dir = ".";
	string prev_dir = "..";

	stack<string> s;

	for(int i=0; i<path.size(); ++i)
	{
		if(path[i] != curr_dir && path[i] != prev_dir){
			s.push(path[i]);
		}
		else if(path[i] == prev_dir){
			s.pop();
		}
		// if path[i] == curr_dir --> no op
	}

	vector<string> n_path;
	while(s.size()){
		string d = s.top();
		n_path.push_back(d);
		s.pop();
	}

	for(int i=0; i<n_path.size()/2; ++i)
	{
		string temp = n_path[n_path.size() - i - 1];
		n_path[n_path.size() - i -1] = n_path[i];
		n_path[i] = temp;
	}

	return n_path;
}


int main()
{
	vector<string> path = {".", "dir1", ".", "..", "dir2", "dir3", "dir4", ".."};
	vector<string> n_path = get_normalized_path(path);

	for(int i=0; i<n_path.size(); ++i)
	{
		cout << n_path[i] << "/";
	}

	cout << endl;
}