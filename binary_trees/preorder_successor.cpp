#include <iostream>
#include <memory>
#include <stack>

using namespace std;
/*
Purpose: Given a binary tree and a node in it, find the successor to it when doing preorder traversal. 
*/

template <typename T>
struct BinaryTreeNode{
	BinaryTreeNode();
	BinaryTreeNode(const T& v, const shared_ptr<BinaryTreeNode<T> >& parent=NULL);
	T data;
	shared_ptr<BinaryTreeNode<T> > parent;
	shared_ptr<BinaryTreeNode<T> > left;
	shared_ptr<BinaryTreeNode<T> > right;
};

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode()
{
	left = NULL;
	right = NULL;
	parent = NULL;
}

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(const T& v, const shared_ptr<BinaryTreeNode<T> >& p)
{
	data = v;
	left = NULL;
	right = NULL;
	parent = p;
}


template <class T>
class BinaryTree{
public:
	BinaryTree();
	shared_ptr<BinaryTreeNode<T> >& get_root();
	void inorder() const;
private:
	shared_ptr<BinaryTreeNode<T> > d_root;
	void inorder_helper(const shared_ptr<BinaryTreeNode<T> >& node) const; 
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
shared_ptr<BinaryTreeNode<T> > get_preorder_successor(shared_ptr<BinaryTreeNode<T> > node)
{
	if(!node){
		return NULL;
	}

	// There are two cases to consider:
	// 1) The node has a left child. 
	//    * This is the successor.
	// 2) The node does not have a left child and has a right child
	//    * The right child is the successor
	// 3) Keep looking at the parent. 
	//    If the parent has a right child, that is not the node itself, the right child is the successor. 
	
	cout << "node->data  = " << node->data << endl;

	// Case 1
	if(node->left){
		return node->left;
	}

	// Case 2
	if(node->right){
		return node->right;
	}

	// Case 3
	cout << "case 3" << endl;
	while(node){
		shared_ptr<BinaryTreeNode<T> > parent = node->parent;
		if(!parent){
			return NULL;
		}

		cout << "parent->data = " << parent->data << endl;

		if(parent->right != node){
			if(parent->right){
				return parent->right;
			}
		}

		node = parent;
	}

	
	cout << "No successor" << endl;
	return NULL;
}



void test1()
{
	BinaryTree<int> t;
	shared_ptr<BinaryTreeNode<int> >& root = t.get_root();

	/*
	Construct a binary tree:
	           10
	          /  \
	         /    \
	        25    20
	       / \    / \  
	      6   5  7   1 
	                  \
	                   6 
	                  /
	                 2 
	Inorder: 6 25 5 10 7 20 1 2 6
	Preorder: 10 25 6 5 20 7 1 6 2
	*/

	root = make_shared<BinaryTreeNode<int> >(10);
	root->left = make_shared<BinaryTreeNode<int> >(25, root);
	root->right = make_shared<BinaryTreeNode<int> >(20, root);
	root->left->right = make_shared<BinaryTreeNode<int> >(5, root->left);
	root->left->left = make_shared<BinaryTreeNode<int> >(6, root->left);
	root->right->left = make_shared<BinaryTreeNode<int> >(7, root->right);
	root->right->right = make_shared<BinaryTreeNode<int> >(1, root->right);
	root->right->right->right = make_shared<BinaryTreeNode<int> >(6, root->right->right);
	root->right->right->right->left = make_shared<BinaryTreeNode<int> >(2, root->right->right->right);
	
	

	/*
	Construct a binary tree:
	           10
	          /  \
	         /    \
	        25    20 
	Inorder: 25 10 20
	*/


	/*
	root = make_shared<BinaryTreeNode<int> >(10);
	root->left = make_shared<BinaryTreeNode<int> >(25, root);
	root->right = make_shared<BinaryTreeNode<int> >(20, root);
	*/

	t.inorder();

	shared_ptr<BinaryTreeNode<int> > preorder_successor = get_preorder_successor<int>(root->right->right->right->left);
	if(preorder_successor){
		cout << "preorder_successor = " << preorder_successor->data << endl;

	}
}

int main()
{
	test1();
}