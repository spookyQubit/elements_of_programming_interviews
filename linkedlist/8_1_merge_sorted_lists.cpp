#include <iostream>
#include <memory>

using namespace std;

template <typename T>
struct Node{
	T data;
	Node<T>* next;
};


template <typename T>
class LinkedList
{
public:
	LinkedList();
	void insertAtEnd(T d);
	void printList() const;
	Node<T>* getHead();
	void setHead(Node<T>* head);
private:
	Node<T>* d_head;
	void makeNode(Node<T>** node, T d);
};



template <typename T>
LinkedList<T>::LinkedList()
{
	d_head = NULL;
}

template <typename T>
void LinkedList<T>::insertAtEnd(T d)
{
	Node<T>* to_be_inserted = new(Node<T>);
	makeNode(&to_be_inserted, d);

	if(!d_head){
		d_head = to_be_inserted;
		return;
	}

	Node<T>* current = d_head;
	while(current->next){
		current = current->next;
	}

	current->next = to_be_inserted;
}

template <typename T>
void LinkedList<T>::printList() const
{
	Node<T>* temp = d_head;
	while(temp){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

template <typename T>
Node<T>* LinkedList<T>::getHead()
{
	return d_head;
}

template <typename T>
void LinkedList<T>::setHead(Node<T>* head)
{
	d_head = head;
}

template<typename T>
void LinkedList<T>::makeNode(Node<T>** node, T d)
{
	*node = new(Node<T>);
	(*node)->data = d;
	(*node)->next = NULL;
}


template <typename T>
LinkedList<T> mergeLists(Node<T>* h1, Node<T>* h2)
{

	Node<T>* temp = NULL;
	LinkedList<T> merged;

	if(h1->data <= h2->data){
		merged.setHead(h1);
		temp = h1;
		h1 = h1->next;
	}
	else{
		merged.setHead(h2);
		temp = h2;
		h2 = h2->next;
	}

	while(h1 && h2){
		if(h1->data <= h2->data){
			temp->next = h1;
			h1 = h1->next;
			temp = temp->next;
		}
		else{
			temp->next = h2;
			h2 = h2->next;
			temp = temp->next;
		}
	}

	while(h1){
		temp->next = h1;
		h1 = h1->next;
		temp = temp->next;
	}

	while(h2){
		temp->next = h2;
		h2 = h2->next;
		temp = temp->next;
	}

	return merged;
}

// EPI Solution
template<typename T>
void appendNode(Node<T>** pt, Node<T>** pt_tail)
{
	(*pt_tail)->next = *pt;
	*pt_tail = *pt;
	*pt = (*pt)->next;
}

template<typename T> 
Node<T>* mergeListsEPI(Node<T>* h1, Node<T>* h2)
{
	Node<T>* dummy_head = new(Node<T>);
	auto tail = dummy_head;

	while(h1 && h2){
		appendNode(h1->data < h2->data ? &h1 : &h2, &tail);
	}

	tail->next = h1 ? h1 : h2;
	return dummy_head->next;
}


int main()
{
	LinkedList<int> l1;
	l1.insertAtEnd(2);
	l1.insertAtEnd(5);
	l1.insertAtEnd(7);
	l1.insertAtEnd(9);
	l1.printList();

	LinkedList<int> l2;
	l2.insertAtEnd(3);
	l2.insertAtEnd(5);
	l2.insertAtEnd(9);
	l2.insertAtEnd(20);
	l2.insertAtEnd(25);
	l2.printList();

	//LinkedList<int> merged_list = mergeLists(l1.getHead(), l2.getHead());
	//merged_list.printList();

	// EPI solution
	Node<int>* m = mergeListsEPI(l1.getHead(), l2.getHead());
	LinkedList<int> merged_list_epi;
	merged_list_epi.setHead(m);
	merged_list_epi.printList();

}