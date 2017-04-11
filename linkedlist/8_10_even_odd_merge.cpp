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
	void even_odd_merge();
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
void List<T>::even_odd_merge()
{
	if(!d_head){
		return;
	}

	auto odd_head = d_head->next;
	auto even = d_head;
	auto odd = d_head->next;
	shared_ptr<Node<T> > pre_even = NULL;

	while(odd && even){
		even->next = odd->next;
		pre_even = even;
		even = even->next;

		if(even){
			odd->next = even->next;
			odd = odd->next;
		}
	}

	pre_even->next = odd_head;
}


int main()
{
	List<int> l;
	l.push_front(5);
	l.push_front(4);
	l.push_front(3);
	l.push_front(2);
	l.push_front(1);
	l.push_front(0);

	l.print_list();
	l.even_odd_merge();
	l.print_list();
}