#include <iostream>
#include <memory>

using namespace std;
/*
Purpose: Given a binary tree find if there exists a leaf where the root to the leaf path has a specified sum.
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
void has_specified_root_to_leaf_sum_helper(const shared_ptr<BinaryTreeNode<T> >& node, 
	                                       int desired_sum, 
	                                       int partial_sum, 
	                                       bool& status)
{
	if(!node){
		return;
	}

	if(status){
		return;
	}

	partial_sum = partial_sum + node->data;
	if(!node->left && !node->right){
	// This is a leaf
		if(partial_sum == desired_sum){
			status = true;
			return;
		}
	}
	has_specified_root_to_leaf_sum_helper(node->left, desired_sum, partial_sum, status);
	has_specified_root_to_leaf_sum_helper(node->right, desired_sum, partial_sum, status);
}

template <typename T>
bool has_specified_root_to_leaf_sum(const shared_ptr<BinaryTreeNode<T> >& node, int desired_sum)
{
	bool status = false;
	has_specified_root_to_leaf_sum_helper(node, desired_sum, 0, status);
	return status;
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
	common_ancestor(6, 5) --> 25
	common_ancestor(20, 1) --> 20 
	*/

	root = make_shared<BinaryTreeNode<int> >(10);
	root->left = make_shared<BinaryTreeNode<int> >(25);
	root->right = make_shared<BinaryTreeNode<int> >(20);
	root->left->right = make_shared<BinaryTreeNode<int> >(5);
	root->left->left = make_shared<BinaryTreeNode<int> >(6);
	root->right->left = make_shared<BinaryTreeNode<int> >(7);
	root->right->right = make_shared<BinaryTreeNode<int> >(1);
	root->right->right->right = make_shared<BinaryTreeNode<int> >(6);
	root->right->right->right->left = make_shared<BinaryTreeNode<int> >(2);


	t.inorder();

	// Get whether there is a leaf in t such that the sum of root to the leaf has a specified sum. 
	cout << "has_specified_root_to_leaf_sum = " 
	     << has_specified_root_to_leaf_sum<int>(root, 37)
	     << endl;

}

int main()
{

	test1();

}