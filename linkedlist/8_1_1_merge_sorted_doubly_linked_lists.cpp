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
	//shared_ptr<Node<T> > getTail();

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
	shared_ptr<Node<T> > pt_node = make_shared<int>(d);
	
	pt_node->prev = d_tail;
	d_tail->next = pt_node;
}

template<typename T>
shared_ptr<Node<T> > DoubleLinkList<T>::getHead()
{
	return d_head;
}


// MergeList
template<typename T>
void append(shared_ptr<Node<T> >* h,  shared_ptr<Node<T> >* tail)
{
	(*h)->prev = (*tail)->next;
	(*tail)->next = *h;
	*tail = *h;
	*h = (*h)->next;
}

template<typename T>
DoubleLinkList<T> getMergedList(DoubleLinkList<T> dl1, DoubleLinkList<T> dl2)
{
	shared_ptr<Node<T> > h1 = dl1.getHead();
	shared_ptr<Node<T> > h2 = dl2.getHead();

	shared_ptr<Node<T> > dummy_head = make_shared<Node<T> >();
	auto tail = dummy_head;

	while(h1 && h2){
 		append(h1->data <= h2->data ? &h1 : &h2, &tail);
	}

	tail->next = h1 ? h1 : h2;

	return DoubleLinkList<T>(dummy_head->next, tail);
}

int main()
{
	DoubleLinkList<int> dl1;
	dl1.push_front(25);
	dl1.push_front(22);
	dl1.push_front(20);
	dl1.push_front(10);
	dl1.printList();

	DoubleLinkList<int> dl2;
	dl2.push_front(35);
	dl2.push_front(30);
	dl2.push_front(29);
	dl2.push_front(15);
	dl2.push_front(11);
	dl2.printList();

	DoubleLinkList<int> d = getMergedList<int>(dl1, dl2);
	d.printList();
}