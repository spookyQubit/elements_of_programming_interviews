#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/*
Purpose: Evaluate Reverse-Polish-Expression
.AB = A.B
Example:
+ * 1 2 3 = + (1*2) 3 = + 2 3 = 2 + 3 = 5
*/


bool is_operator(const string& c)
{
	if(c=="*" || c=="/" || c=="+" || c=="-"){
		return true;
	}
	return false;
}

char get_operator(const string& c)
{
	if(c=="*"){
		return '*';
	}
	if(c=="/"){
		return '/';
	}
	if(c=="+"){
		return '+';
	}
	if(c=="-"){
		return '-';
	}
	return '~';
}

int evalute_pn(const std::vector<string>& exp)
{
	stack<int> s;
	
	for(int i=exp.size()-1; i>=0; --i)
	{
		if(is_operator(exp[i]))
		{
			int y = s.top();
			s.pop();
			int x = s.top();
			s.pop();

			switch(get_operator(exp[i]))
			{
				case '+':
				{
					s.emplace(x + y);
					break;
				}
				case '-':
				{
					s.emplace(x - y);
					break;
				}
				case '/':
				{
					s.emplace(x / y);
					break;
				}
				case '*':
				{
					s.emplace(x * y);
					break;
				}
			}
		}
		else{
			s.emplace(stoi(exp[i]));
		}
	}

	return s.top();
}


int main()
{
	vector<string> exp = {"+", "*", "1", "2", "3"};
	cout << "evalute_pn(exp) = " << evalute_pn(exp) << endl;
}