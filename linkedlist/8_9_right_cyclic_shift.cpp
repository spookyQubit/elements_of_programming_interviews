#include <iostream>
#include <memory>

using namespace std;

template <typename T>
struct Node{
	T data;
	shared_ptr<Node<T> > next;
	Node<T>(T d) : data(d), next(NULL){}
};


template <class T>
class List
{
public:
	void push_front(T d);
	void print_list() const;
	void remove_duplicates();
	void right_cyclic_shift(int k);
private:
	shared_ptr<Node<T> > d_head;
};


template <typename T>
void List<T>::push_front(T d)
{
	shared_ptr<Node<T> > temp = make_shared<Node<T> >(d);

	temp->next = d_head;
	d_head = temp;
}

template <typename T>
void List<T>::print_list() const
{
	shared_ptr<Node<T> > temp = d_head;
	while(temp){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}


template <typename T>
void List<T>::right_cyclic_shift(int k)
{
	if(!d_head){
		return;
	}

	auto temp = d_head;
	int l = 1;
	while(temp->next)
	{
		temp = temp->next;
		++l;
	}

	temp->next = d_head;
	k = k % l;
	for(int i = 0; i < l-k; ++i){
		temp = temp->next;
	}

	d_head = temp->next;
	temp->next = NULL;
}


int main()
{
	List<int> l;
	l.push_front(1);
	l.push_front(2);
	l.push_front(3);
	l.push_front(4);
	l.print_list();

	int k = 3;
	l.right_cyclic_shift(k);
	l.print_list();
}