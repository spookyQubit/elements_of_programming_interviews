#include <iostream>
#include <memory>

using namespace std;
/*
Purpose: Given a linked list with unknown length, delete the kth last node from the end.
*/

template <typename T>
struct Node{
	T data;
	shared_ptr<Node<T> > next;
	Node<T>(){}
	Node(T d):data(d), next(NULL){} 
};


template <class T>
class List{
public:
	List(): d_head(NULL){}
	void push_front(T d);
	void print_list() const;
	inline shared_ptr<Node<T> > get_head(){ return d_head; }
	inline void set_head(shared_ptr<Node<T> > h){ d_head = h; }
private:
	shared_ptr<Node<T> > d_head;
};


template <typename T>
void List<T>::push_front(T d)
{
	shared_ptr<Node<T> > new_node = make_shared<Node<T> >(d);
	
	shared_ptr<Node<T> > temp = d_head;
	d_head = new_node;
	new_node->next = temp;
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
void delete_kth_last(List<T>& l, int k)
{
	shared_ptr<Node<T> > h = l.get_head();

	shared_ptr<Node<T> > front = h;
	shared_ptr<Node<T> > back = h;
	for(int i=0; i<k; ++i)
	{
		if(!front){
			cout << "Not k elements in the list." << endl;
			return;
		}
		front = front->next;
	}

	// Check the case where the head needs to be deleted.
	if(!front){
		h = h->next;
		l.set_head(h);
		return;
	}

	while(front->next){
		front = front->next;
		back = back->next;
	}

	back->next = back->next->next;
}

int main()
{
	List<int> l;
	l.push_front(10);
	l.push_front(20);
	//l.push_front(30);
	l.print_list();

	int k = 2;
	delete_kth_last(l, k);
	l.print_list();
}