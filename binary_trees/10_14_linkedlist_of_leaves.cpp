#include <iostream>
#include <memory>
#include <stack>
#include <vector>
#include <assert.h>
#include <forward_list>

using namespace std;
/*
Purpose: Given a binary tree, form a linked list of leaves. 
         The order should be from left to right.   
*/

template <typename T>
struct BinaryTreeNode{
	BinaryTreeNode();
	BinaryTreeNode(const T& v);
	T data;
	shared_ptr<BinaryTreeNode<T> > left;
	shared_ptr<BinaryTreeNode<T> > right;
};

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode()
{
	left = NULL;
	right = NULL;
}

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(const T& v)
{
	data = v;
	left = NULL;
	right = NULL;
}


template <class T>
class BinaryTree{
public:
	BinaryTree();
	shared_ptr<BinaryTreeNode<T> >& get_root();
	void inorder() const;
	void preorder() const;
	void postorder() const;
private:
	shared_ptr<BinaryTreeNode<T> > d_root;
	void inorder_helper(const shared_ptr<BinaryTreeNode<T> >& node) const;
	void preorder_helper(const shared_ptr<BinaryTreeNode<T> >& node) const; 
	void postorder_helper(const shared_ptr<BinaryTreeNode<T> >& node) const;
};

template <typename T>
BinaryTree<T>::BinaryTree()
{
	d_root = NULL;
}

template <typename T>
shared_ptr<BinaryTreeNode<T> >& BinaryTree<T>::get_root()
{
	return d_root;
}

template <typename T>
void BinaryTree<T>::inorder_helper(const shared_ptr<BinaryTreeNode<T> >& node) const
{
	if(!node){
		return;
	}

	this->inorder_helper(node->left);
	cout << node->data << endl;
	this->inorder_helper(node->right);
}

template <typename T>
void BinaryTree<T>::inorder() const
{
	this->inorder_helper(d_root);
}

template <typename T>
void BinaryTree<T>::preorder_helper(const shared_ptr<BinaryTreeNode<T> >& node) const
{
	if(!node){
		return;
	}

	cout << node->data << endl;
	this->preorder_helper(node->left);
	this->preorder_helper(node->right);
}

template <typename T>
void BinaryTree<T>::preorder() const
{
	this->preorder_helper(d_root);
}


template <typename T>
void BinaryTree<T>::postorder_helper(const shared_ptr<BinaryTreeNode<T> >& node) const
{
	if(!node){
		return;
	}
	this->postorder_helper(node->left);
	this->postorder_helper(node->right);
	cout << node->data << endl;
}

template <typename T>
void BinaryTree<T>::postorder() const
{
	this->postorder_helper(d_root);
}

template <typename T>
void get_list_of_leaves(shared_ptr<BinaryTreeNode<T> > node, forward_list<T>& l)
{
	if(!node){
		return;
	}

	get_list_of_leaves(node->right, l);
	get_list_of_leaves(node->left, l);

	if(!node->left && !node->right)
	{
		cout << "node->data = " << node->data << endl;
		l.emplace_front(node->data);
	}
}


void test1()
{
	/*
	Construct a binary tree:
	           10
	          /  \
	         /    \
	        25    20 
	       / \    / \
	      6   5  7   1
	                  \
	                   9
	Inorder: 6 25 5 10 7 20 1 9
	Preorder: 10 25 6 5 20 7 1 9
	Postorder: 6 5 25 7 9 1 20 10
	L = 6 -> 5 -> 7 -> 9
	*/

	BinaryTree<int> t;
	shared_ptr<BinaryTreeNode<int> >& root = t.get_root();
	
	root = make_shared<BinaryTreeNode<int> >(10);
	root->left = make_shared<BinaryTreeNode<int> >(25);
	root->left->left = make_shared<BinaryTreeNode<int> >(6);
	root->left->right = make_shared<BinaryTreeNode<int> >(5);
	root->right = make_shared<BinaryTreeNode<int> >(20);
	root->right->left = make_shared<BinaryTreeNode<int> >(7);
	root->right->right = make_shared<BinaryTreeNode<int> >(1);
	root->right->right->right = make_shared<BinaryTreeNode<int> >(9);
	

	cout << "inorder" << endl;
	t.inorder();

	// Get linked list of leaves
	forward_list<int> l; 
	get_list_of_leaves(root, l);

	for(auto iter = l.begin(); iter != l.end(); ++iter)
	{
		cout << *iter << endl;
	}

}

int main()
{
	test1();
}