#include <iostream>
#include <queue>
#include <functional>
#include <vector>

using namespace std;

/*
Purpose: Implement a stack using heap.
Stack: The stack should support:
       1) Push 
       2) Pop --> Removes the last entered element. Throws exception if empty.
       3) Top --> Returns the last eneterd element. Throws exception if empty.
*/

struct HeapNode
{
	int value;
	int index;
	HeapNode(int i, int v): index(i), value(v) {}
};

priority_queue<HeapNode, vector<HeapNode>, function<bool(HeapNode, HeapNode)> > 
	cun([](HeapNode a, HeapNode b){ return a.value < b.value; });


//template <typename T>
class Stack{
private:
	priority_queue<HeapNode, vector<HeapNode>, function<bool(HeapNode, HeapNode)> > 
	d_queue;
public:
	Stack();
	void push(const int& v);
	void pop();
	const int& top() const;
};


Stack::Stack() : d_queue([](HeapNode a, HeapNode b){ return a.index < b.index; })
{
	// Emty Constructor

}

void Stack::push(const int& v)
{
	if(d_queue.empty()){
		d_queue.emplace(0, v);
		return;
	}

	int max_index = d_queue.top().index;
	d_queue.emplace(max_index + 1, v);
}

void Stack::pop()
{
	if(d_queue.empty()){
		throw length_error("Empty");
	}

	d_queue.pop();
}

const int& Stack::top() const
{
	if(d_queue.empty()){
		throw length_error("Empty");
	}

	return d_queue.top().value;
}
uiii
void test1()
{
	Stack s;

	s.push(10);
	s.push(20);
	s.push(1);
	s.push(2);
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
}


int main()
{
	test1();
}