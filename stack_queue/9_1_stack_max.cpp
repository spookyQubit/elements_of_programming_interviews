#include <iostream>
#include <stack>

using namespace std;

template <class T>
class Stack : public stack<pair<T, T> >
{
public:
	void push(const T& v);
	T top() const;
	T max() const;
	void print() const;
private:
	T d_max_till_now;
};

template <typename T>
void Stack<T>::push(const T& v)
{
	if(this->empty()){
		d_max_till_now = v;
	}

	d_max_till_now = v > d_max_till_now ? v : d_max_till_now;
	this->stack<pair<T, T> >::push(make_pair(v, d_max_till_now));
}

template <typename T>
T Stack<T>::top() const 
{
	pair<T, T> p = this->stack<pair<T, T> >::top();
	return p.first;
}

template <typename T>
T Stack<T>::max() const
{
	pair<T, T> p = this->stack<pair<T, T> >::top();
	return p.second;
}


template <typename T>
void Stack<T>::print() const
{
	Stack<T> s = *this;
	while(!s.empty()){
		pair<T, T> p = s.stack<pair<T, T> >::top();
		s.pop();

		cout << p.first << " " << p.second << " | "; 
	}
	cout << endl;
}



int main()
{
	Stack<int> s;
	s.push(0);
	s.push(10);
	s.push(5);
	s.push(15);
	s.push(30);
	s.push(15);

	s.print();

	s.pop();
    s.print();

    s.pop();
    s.print();

}