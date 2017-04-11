#include <iostream>
#include <memory>

using namespace std;

/*
Purpose:
Given a sorted linked list whith duplicates, remove all duplicates and return a sorted list without duplicates.
*/

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
void List<T>::remove_duplicates()
{
	if(!d_head){
		return;
	}

	shared_ptr<Node<T> > pre_insert_node = d_head;
	shared_ptr<Node<T> > to_insert_node = d_head->next;
	shared_ptr<Node<T> > current_node = d_head->next;

	T value = d_head->data;

	while(current_node){
		if(value != current_node->data){
			to_insert_node->data = current_node->data;
			value = to_insert_node->data;	

			pre_insert_node = pre_insert_node->next;
			to_insert_node = to_insert_node->next;
		}
		current_node = current_node->next;
	}

	pre_insert_node->next = NULL;
	to_insert_node = NULL;
	current_node = NULL;
}

int main()
{
	List<int> l;
	l.push_front(10);
	l.push_front(10);
	l.push_front(20);
	l.push_front(30);
	l.push_front(30);
	l.push_front(30);
	l.push_front(40);
	l.push_front(40);
	l.print_list();

	l.remove_duplicates();
	l.print_list();
}