#include <iostream>
#include <memory>
#include <unordered_set>

using namespace std;

/*
Purpose: 
Two linked lists are given, Determine if they overlap. 
1) One can store all the addresses of l1 in a hash map and then while travelling l2, 
if we find the address in the hash map, we know there is overlap. 
2) If both lists have the same tail, then there is an overlap. 
*/


template <typename T>
struct Node{
	T data;
	shared_ptr<Node<T> > next;
	Node(T d): data(d), next(NULL) {}
};

template <class T>
class List
{
public:
	List(){ d_head = NULL; }
	shared_ptr<Node<T> > push_front(T d);
	void print_list() const;
	inline shared_ptr<Node<T> > get_head() { return d_head; }
private:
	shared_ptr<Node<T> > d_head;
};


template <typename T>
shared_ptr<Node<T> > List<T>::push_front(T d)
{
	shared_ptr<Node<T> > temp = make_shared<Node<T> >(d);
	if(!d_head){
		d_head = temp;
		return d_head;
	}

	shared_ptr<Node<T> > current = d_head;
	temp->next = current;
	d_head = temp;
	return d_head;
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
shared_ptr<Node<T> > get_overlap_node(shared_ptr<Node<T> > h1, shared_ptr<Node<T> > h2)
{
	unordered_set<shared_ptr<Node<T> > > s;
	while(h1){
		s.insert(h1);
		h1 = h1->next;
	}

	while(h2){
		auto ret = s.insert(h2);
		if(!ret.second){
			return h2;
		}
		h2 = h2->next;
	} 
	return NULL;
} 

int main()
{
	shared_ptr<List<int> > pt_l1 = make_shared<List<int> >(); 
	shared_ptr<Node<int> > pt_10 = pt_l1->push_front(10);
	pt_l1->push_front(20);
	pt_l1->push_front(30);
	pt_l1->push_front(40);
	pt_l1->push_front(50);
	pt_l1->push_front(60);
	pt_l1->push_front(70);
	pt_l1->push_front(80);
	pt_l1->print_list();

	cout << "pt_10->data = " << pt_10->data << endl;

	shared_ptr<List<int> > pt_l2 = make_shared<List<int> >(); 
	pt_l2->push_front(100);
	pt_l2->push_front(200);
	pt_l2->push_front(300);
	pt_l2->push_front(400);
	shared_ptr<Node<int> > pt_500 = pt_l2->push_front(500);
	pt_l2->push_front(501);
	pt_l2->push_front(502);
	pt_l2->print_list();

	// Make end of l1 to point to a node in l2
	pt_10->next = pt_500;
	pt_l1->print_list();
	pt_l2->print_list();

	shared_ptr<Node<int> > pt_overlap_node = get_overlap_node(pt_l1->get_head(), pt_l2->get_head());

	if(pt_overlap_node){
		cout << pt_overlap_node->data << endl;
	}
	else{
		cout << "No overlap" << endl;
	}
}