#include <iostream>
#include <queue>
#include <deque>


using namespace std;

/*
Purpose: Queue with max api
*/

template <class T>
class QueueMax: public queue<T>
{
public:
	void enqueue(const T& v);
	void dequeue();
	T max() const;
private:
	deque<T> d_max_candidate;
}; 


template <typename T>
void QueueMax<T>::dequeue()
{
	if(this->empty()){
		throw length_error("EMPTY");
	}

	// The candidate head == front
	if(d_max_candidate.front() == this->front()){
		d_max_candidate.pop_front();
		this->queue<T>::dequeue();
	}
	else{
		this->queue<T>::dequeue();
	}
}

template <typename T>
void QueueMax<T>::enqueue(const T& v)
{
	this->queue<T>::enqueue(v);

	while(d_max_candidate.back() < v && !d_max_candidate.empty()){
		d_max_candidate.pop_back();
	}

	d_max_candidate.push_back(v);
}

template <typename T>
T QueueMax<T>::max() const 
{
	if(d_max_candidate.empty()){
		throw length_error("EMPTY");
	}

	return d_max_candidate.front();
}


int main()
{
	

}