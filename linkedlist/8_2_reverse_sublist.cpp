#include <iostream>
#include <forward_list>
#include <assert.h>
#include <memory>
using namespace std;

/*
Purpose: Write a function that takes as argument a list L, and two numbers s and f. 
The nodes between s and f (inclusive), i.e. the range [s, f] is to be reversed. 
Elements start at index 1. 
*/

template<typename T>
struct Node{
	T data;
	shared_ptr<Node<T> > next;
	Node(): data(), next(NULL){}
	Node(const T& d): data(d), next(NULL){}
};


template<class T>
class List{
public:
	List(): d_head(NULL){}
	~List(){ /* no need to implement */ }
	void pushFront(T d);
	shared_ptr<Node<T> > getHead();
	void setHead(shared_ptr<Node<T> > head);
	void printList() const;
private:
	shared_ptr<Node<T> > d_head;
};

template<typename T>
void List<T>::pushFront(T d)
{
	shared_ptr<Node<T> > temp = make_shared<Node<T> >(d);
	temp->next = d_head;
	d_head = temp;
}

template<typename T>
shared_ptr<Node<T> > List<T>::getHead()
{
	return d_head;
}

template<typename T>
void List<T>::setHead(shared_ptr<Node<T> > head)
{
	d_head = head;
}

template<typename T>
void List<T>::printList() const
{
	shared_ptr<Node<T> > temp = d_head;
	while(temp){
		cout << temp->data << " ";
		temp = temp->next;
	}

	cout << endl;
}

// Reverse the entire list
template<typename T>
void reverse(shared_ptr<List<T> > pt_l)
{
	shared_ptr<Node<T> > prev = NULL;
	shared_ptr<Node<T> > current = pt_l->getHead();

	while(current){
		shared_ptr<Node<T> > temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}

	pt_l->setHead(prev);
}

template<typename T>
void reverseSublist(shared_ptr<List<T> > pt_l, int s, int f)
{
	if(!pt_l){
		return;
	}

	shared_ptr<Node<T> > pre_sublist = NULL;

	int k = 1;
	while(k < s){
		if(!pre_sublist && k == 1){
			pre_sublist = pt_l->getHead();
		}
		else if(pre_sublist && k > 1){
			pre_sublist = pre_sublist->next;
		}
		++k;
	}

	shared_ptr<Node<T> > prev = pre_sublist->next; // Assuming next exists
	shared_ptr<Node<T> > current = pre_sublist->next->next; // Assuming next->next exists

	while(k < f){
		shared_ptr<Node<T> > temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
		++k;
	}

	pre_sublist->next->next = current;
	pre_sublist->next = prev;

}




int main()
{
	shared_ptr<List<int> > pt_l = make_shared<List<int> >();
	pt_l->pushFront(10);
	pt_l->pushFront(30);
	pt_l->pushFront(40);
	pt_l->pushFront(50);
	pt_l->pushFront(60);
	pt_l->pushFront(70);
	pt_l->printList();

	reverse(pt_l);
	pt_l->printList();

	int s = 3;
	int f = 5;
	reverseSublist(pt_l, s, f);
	pt_l->printList();
}