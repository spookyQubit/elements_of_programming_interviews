#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <assert.h>

using namespace std;
/*
Purpose: Check whether the string is is well formed with respect to {}, (), []

({)} ---> Not well formed
({}) ---> Well formed

*/

bool is_left_bracket(char c)
{
	if(c=='(' || c=='{' || c=='['){
		return true;
	}

	return false;
}

char get_correspondig_lb(char rb)
{
	switch(rb){
		case ')':
		return '(';
		case '}':
		return '{';
		case ']':
		return '[';
	}

	return '~';
}

bool is_well_formed(const string& exp)
{
	stack<char> s;
	for(int i=0; i<exp.size(); ++i)
	{
		if(is_left_bracket(exp[i])){
			s.push(exp[i]);
		}
		else{
			// We have a right bracket
			if(s.empty()){
				// This can happen when number of right brackets > number of left brackets
				return false;
			}

			char lb = s.top();
			s.pop();
			if(lb != get_correspondig_lb(exp[i])){
				// This will happen if {[}]
				return false;
			}
		}
	}

	if(s.size() > 0){
		// This can happen when number of right brackets < number of left brackets
		return false;
	}

	return true;
}

int main()
{
	string exp1 = "([){}";
	cout << exp1 << " is_well_formed = " << is_well_formed(exp1) << endl; 
    
    string exp2 = "{{{}}}()()";
    cout << exp2 << " is_well_formed = " << is_well_formed(exp2) << endl;
    assert(is_well_formed(exp2));

}