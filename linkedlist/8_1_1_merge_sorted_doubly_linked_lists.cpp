#include <iostream>
#include <memory>

using namespace std;

/*
Purpose: Given two doubly sorted linked lists, merge them. 
*/

template<typename T>
struct Node{
	T data;
	shared_ptr<Node<T> > next;
	shared_ptr<Node<T> > prev;
	Node(): data(), next(NULL), prev(NULL){}
	Node(const T& d): data(d), next(NULL), prev(NULL){}
};


template<class T>
class DoubleLinkList
{
public:
	DoubleLinkList();
	DoubleLinkList(shared_ptr<Node<T> > h, shared_ptr<Node<T> > t);
	~DoubleLinkList();
	void printList() const;
	void push_front(T d);
	void push_back(T d);

	shared_ptr<Node<T> > getHead();

private:
	shared_ptr<Node<T> > d_head;
	shared_ptr<Node<T> > d_tail;
};

template<typename T>
DoubleLinkList<T>::DoubleLinkList()
{
	d_head = NULL;
	d_tail = NULL;
}

template<typename T>
DoubleLinkList<T>::DoubleLinkList(shared_ptr<Node<T> > h, shared_ptr<Node<T> > t)
{
	d_head = h;
	d_tail = t;
}

template<typename T>
DoubleLinkList<T>::~DoubleLinkList()
{
	// Nothing needs to be done here. 
}

template<typename T>
void DoubleLinkList<T>::printList() const
{
	shared_ptr<Node<T> > temp = d_head;
	while(temp)
	{
		cout << temp->data << " ";
		temp = temp->next; 
	}
	cout << endl;
}

template<typename T>
void DoubleLinkList<T>::push_front(T d)
{
	shared_ptr<Node<T> > pt_node = make_shared<Node<T> >(d);
	
	pt_node->next = d_head;
	d_head = pt_node;
}

template<typename T>
void DoubleLinkList<T>::push_back(T d)
{
	shared_ptr<Node<T> > pt_node = make_shared<int>(d);;
	
	pt_node->prev = d_tail;
	d_tail->next = pt_node;
}



int main()
{
	DoubleLinkList<int> dl;
	dl.push_front(10);
	dl.push_front(20);
	dl.printList();
}