#include <iostream>
#include <stack>

using namespace std;


/*
Purpose: Make queue using stack
*/


class QueueWithStack{
private:
	stack<int> d_stack_1; // Will be used for enqueueing
	stack<int> d_stack_2; // Will be used for dequeueing
public:
	void enqueue(int v);
	int front();
	void dequeue();
};



void QueueWithStack::enqueue(int v)
{
	d_stack_1.push(v);
}


int QueueWithStack::front()
{
	if(d_stack_1.empty() && d_stack_2.empty()){
		cout << "The queueu is empty" << endl;
		throw length_error("empty queue");
	}

	// The queue is not empty.
	if(!d_stack_2.empty()){
		return d_stack_2.top();
	}

	// d_stact_2 is empty. 
	// Empty d_skack_1 into d_stack_2 and then return the top of d_stack_2
	while(!d_stack_1.empty()){
		int temp = d_stack_1.top();
		d_stack_2.push(temp);
		d_stack_1.pop();
	}

	return d_stack_2.top();
}


void QueueWithStack::dequeue()
{
	if(d_stack_1.empty() && d_stack_2.empty()){
		cout << "The queueu is empty" << endl;
		throw length_error("empty queue");
	}

	// The queue is not empty.
	if(!d_stack_2.empty()){
		d_stack_2.pop();
		return;
	}

	// d_stact_2 is empty. 
	// Empty d_skack_1 into d_stack_2 and then return the top of d_stack_2
	while(!d_stack_1.empty()){
		int temp = d_stack_1.top();
		d_stack_2.push(temp);
		d_stack_1.pop();
	}

	d_stack_2.pop();
}

int main()
{
	QueueWithStack q;

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);

	cout << q.front() << endl;
	q.dequeue();

	cout << q.front() << endl;
	q.dequeue();

	cout << q.front() << endl;
	q.dequeue();
	
}
