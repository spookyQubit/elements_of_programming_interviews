#include <iostream>
#include <queue>
#include <vector>

using namespace std;


/*
Purpose: Given a max heap, find the K largest entries.
*/

vector<int> get_k_max_elements(const priority_queue<int>& h, int k)
{
	
}

void test1()
{
	priority_queue<int> h;
	h.push(10);
	h.push(20);
	h.push(5);
	h.push(30);
	h.push(25);

	int k = 3;
	vector<int> result = get_k_max_elements(h, k);

}

int main()
{
	test1();
}