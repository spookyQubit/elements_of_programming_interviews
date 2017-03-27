#include <iostream>
#include <memory>

using namespace std;

/*
Purpose: Test for cycles in a link list
1) Have one slow and one fast iterator.
2) If the fast and slow iter meet, before fast goes to NULL, then there is a cycle.
3) Find the number of nodes (length) of the cycle.
4) Given the length, find the node at which the cycle starts.
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
shared_ptr<Node<T> > has_cycle(shared_ptr<Node<T> > head)
{
	if(!head){
		return NULL;
	}

	shared_ptr<Node<T> > slow = head;
	shared_ptr<Node<T> > fast = head;
	while(fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast){ 
		// has cycle
			// Find the length of the cycle.
			fast = fast->next;
			int cycle_length = 1;
			while(slow != fast){
				fast = fast->next;
				++cycle_length;
			}

			// Find the beginning of the cycle.
			shared_ptr<Node<T> > temp1 = head;
			shared_ptr<Node<T> > temp2 = head;
			for(int i = 0; i < cycle_length; ++i)
			{
				temp2 = temp2->next;
			}

			while(temp1 != temp2){
				temp1 = temp1->next;
				temp2 = temp2->next; 
			}

			return temp1;
		}
	}

	return NULL;
}

int main()
{
	shared_ptr<List<int> > pt_l = make_shared<List<int> >(); 
	shared_ptr<Node<int> > pt_10 = pt_l->push_front(10);
	pt_l->push_front(20);
	pt_l->push_front(30);
	pt_l->push_front(40);
	shared_ptr<Node<int> > pt_50 = pt_l->push_front(50);
	pt_l->push_front(60);
	pt_l->push_front(70);
	pt_l->push_front(80);

	cout << "pt_10->data = " << pt_10->data << endl;
	cout << "pt_50->data = " << pt_50->data << endl;

	// Create a circle
	pt_10->next = pt_50;

	// Check if there is cycle
	shared_ptr<Node<int> > head_of_cycle = has_cycle(pt_l->get_head());
	cout << "head_of_cycle->data = " << head_of_cycle->data << endl;
}