#include <iostream>
#include <vector>

using namespace std;

/*
1) circular queue
2) constructor with initial size
3) enqueue
4) dequeue
5) number fo elements stored
*/

class CircularQueue{
public:
	CircularQueue(int queue_size);
	void enqueue(int v);
	int dequeue();
	void print() const;
	//int size() const;
private:
	vector<int> d_queue;
	int d_head;
	int d_tail;
	void rotate();
};


CircularQueue::CircularQueue(int queue_size) : d_queue(queue_size)
{
	d_head = -1;
	d_tail = -1;  
}


void CircularQueue::rotate()
{
	int n = d_queue.capacity() - d_head;
	for(int i=0; i<n; ++i)
	{
		int temp1 = d_queue[0];
		for(int j = 1; j < d_queue.size(); ++j)
		{
			int temp2 = d_queue[j];
			d_queue[j] = temp1;
			temp1 = temp2;
		}
		d_queue[0] = temp1;
	}
}

void CircularQueue::enqueue(int v)
{
	// if the queue is not full
	if((d_tail + 1) % d_queue.capacity() != d_head){
		d_tail = (d_tail + 1) % d_queue.capacity();
		d_queue[d_tail] = v;

		if(d_head == -1){
			++d_head;
		}
		return;
	}

	// if it is full
	cout << "The queue is full" << endl;
	// Rotate the elements so that the d_head = 0
	rotate();
	d_head = 0;
	d_tail = d_queue.capacity() - 1;

	d_queue.resize(2 * d_queue.capacity());
	d_queue[++d_tail] = v;
}

int CircularQueue::dequeue()
{
	// If the queue is not empty
	if(d_head != -1){
		int temp = d_queue[d_head];
		if(d_head == d_tail){
			cout << "d_head == d_tail in dequeue" << endl;
			d_head = -1;
			d_tail = -1;
		}
		else{
			d_head = (d_head + 1) % d_queue.capacity();
		}
		return d_head;
	}

	// The queue is empty
	cout << "The queue is empty" << endl;
	return -1;
}



void CircularQueue::print() const 
{
	cout << "d_head = " << d_head
	     << " d_tail = " << d_tail
	     << " d_queue.capacity() =  " << d_queue.capacity()
	     << endl;
	cout << endl;
}


int main()
{
	CircularQueue q(3);
	q.print();
	
	q.enqueue(0);
	q.enqueue(10);
	q.print();
	
	q.dequeue();
	q.print();
	
	q.enqueue(1);
	q.enqueue(2);
	q.print();

	q.enqueue(3);
	q.print();

	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;





}