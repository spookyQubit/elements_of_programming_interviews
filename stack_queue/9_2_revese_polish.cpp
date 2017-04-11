#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/* 
Purpose: Evaluate Reverse-Polish-Expression
AB. = A.B
Example:
1 2 * 3 + = (1*2) + 3 = 5
*/

char get_operator(string c)
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

int evalute_rpn(const vector<string>& exp)
{
	stack<int> s;

	for(int i=0; i<exp.size(); ++i)
	{
		char o = get_operator(exp[i]);
		
		switch(o)
		{
			case '+':
			{
				int y = s.top();
			    s.pop();
			    int x = s.top();
			    s.pop();
			    s.emplace(x+y);
			    break;
			}
			case '-':
			{
				int y = s.top();
			    s.pop();
			    int x = s.top();
			    s.pop();
			    s.emplace(x-y);
			    break;
			}
			case '/':
			{
				int y = s.top();
			    s.pop();
			    int x = s.top();
			    s.pop();
			    s.emplace(x/y);
			    break;
			}
			case '*':
			{
				int y = s.top();
			    s.pop();
			    int x = s.top();
			    s.pop();
			    s.emplace(x*y);
			    break;
			}
			default:
			{
				s.emplace(stoi(exp[i]));
				break;
			}
		}
	}

	return s.top();
}

int main()
{
	vector<string> exp = {"1", "2", "*", "3", "+"};
	//string exp = "1,2,*";
	cout << "evalute_rpn(exp) = " << evalute_rpn(exp) << endl;
}