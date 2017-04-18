#include <iostream>
#include <memory>
#include <assert.h>

using namespace std;

/*
Purpose: To find if a binary tree is symmetric.
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
	bool is_symmetric() const;
private:
	shared_ptr<BinaryTreeNode<T> > d_root;
	void inorder_helper(const shared_ptr<BinaryTreeNode<T> >& node) const;
	bool is_symmetric_helper(const shared_ptr<BinaryTreeNode<T> >& l_node, 
		                     const shared_ptr<BinaryTreeNode<T> >& r_node) const;
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
bool BinaryTree<T>::is_symmetric_helper(const shared_ptr<BinaryTreeNode<T> >& l_node, 
	const shared_ptr<BinaryTreeNode<T> >& r_node) const
{
	if((l_node && !r_node) || (!l_node && r_node)){
		return false;
	}

	if(!l_node && !r_node){
		return true;
	}

	if(l_node->data != r_node->data){
		return false;
	}

	cout << "l_node->data = " << l_node->data
	     << " r_node->data = " << r_node->data
	     << endl;

	return(this->is_symmetric_helper(l_node->left, r_node->right) && 
		   this->is_symmetric_helper(l_node->right, r_node->left));
}

template <typename T>
bool BinaryTree<T>::is_symmetric() const
{
	if(!d_root){
		return true;
	}
	return(this->is_symmetric_helper(d_root->left, d_root->right));
}




void test_case_1()
{
	BinaryTree<int> t;
	shared_ptr<BinaryTreeNode<int> >& root = t.get_root();

	/*
	Construct a binary tree:
	           10
	          /  \
	         /    \
	        20    20
	         \    / 
	          5  5    
	Inorder: 20 5 10 5 20 
	is_symmetric = true
	*/
	shared_ptr<BinaryTreeNode<int> > pt = make_shared<BinaryTreeNode<int> >(10);
	root = pt;

	pt = make_shared<BinaryTreeNode<int> >(20);
	root->left = pt;

	pt = make_shared<BinaryTreeNode<int> >(20);
	root->right = pt;

	pt = make_shared<BinaryTreeNode<int> >(5);
	root->left->right = pt;

	pt = make_shared<BinaryTreeNode<int> >(5);
	root->right->left = pt;

	t.inorder();

	// Check if symmetric
	bool is_symmetric = t.is_symmetric();
	cout << "is_symmetric = " << is_symmetric << endl;

	assert(is_symmetric == true);

}


void test_case_2()
{
	BinaryTree<int> t;
	shared_ptr<BinaryTreeNode<int> >& root = t.get_root();

	/*
	Construct a binary tree:
	           10
	          /  \
	         /    \
	        20    20
	         \    / \  
	          5  5   1  
	Inorder: 20 5 10 5 20 1 
	is_symmetric = false
	*/
	shared_ptr<BinaryTreeNode<int> > pt = make_shared<BinaryTreeNode<int> >(10);
	root = pt;

	pt = make_shared<BinaryTreeNode<int> >(20);
	root->left = pt;

	pt = make_shared<BinaryTreeNode<int> >(20);
	root->right = pt;

	pt = make_shared<BinaryTreeNode<int> >(5);
	root->left->right = pt;

	pt = make_shared<BinaryTreeNode<int> >(5);
	root->right->left = pt;

	pt = make_shared<BinaryTreeNode<int> >(1);
	root->right->right = pt;

	t.inorder();

	// Check if symmetric
	bool is_symmetric = t.is_symmetric();
	cout << "is_symmetric = " << is_symmetric << endl;

	assert(is_symmetric==false);

}


void test_case_3()
{
	BinaryTree<int> t;
	shared_ptr<BinaryTreeNode<int> >& root = t.get_root();

	/*
	Construct a binary tree:
	           10
	          /  \
	         /    \
	        20    20
	       / \    / \  
	      1   5  5   1  
	Inorder: 1 20 5 10 5 20 1 
	is_symmetric = true
	*/
	shared_ptr<BinaryTreeNode<int> > pt = make_shared<BinaryTreeNode<int> >(10);
	root = pt;

	pt = make_shared<BinaryTreeNode<int> >(20);
	root->left = pt;

	pt = make_shared<BinaryTreeNode<int> >(20);
	root->right = pt;

	pt = make_shared<BinaryTreeNode<int> >(5);
	root->left->right = pt;

	pt = make_shared<BinaryTreeNode<int> >(1);
	root->left->left = pt;

	pt = make_shared<BinaryTreeNode<int> >(5);
	root->right->left = pt;

	pt = make_shared<BinaryTreeNode<int> >(1);
	root->right->right = pt;

	t.inorder();

	// Check if symmetric
	bool is_symmetric = t.is_symmetric();
	cout << "is_symmetric = " << is_symmetric << endl;

	assert(is_symmetric==true);

}


int main()
{
	test_case_1();
	test_case_2();
	test_case_3();
}