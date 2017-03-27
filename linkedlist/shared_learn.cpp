#include <iostream>
#include <memory>

using namespace std;


void change(shared_ptr<int> pt)
{
	*pt = 10; 
}

int main()
{
	//int a = 3;
	//shared_ptr<int> pt_a = make_shared<int>(3);


	int& a = *pt_a; 
	
	cout << "a = " << a << endl;
	cout << "*pt_a = " << *pt_a << endl;

    //*pt_a = 50;
    //cout << endl;
	change(pt_a);
	cout << "a = " << a << endl;
	cout << "*pt_a = " << *pt_a << endl;
}