#include <iostream>
#include <memory>

using namespace std;

/*
Purpose: A tree is given with 0/1 values. 
         Each path from the root to a leaf corresponds to a number in base 2. 
         So, if there are 3 leafs, there will be tree numbers. 
         Given such a tree, find the sum of all the numbers. 

         Example:
                1  <-- Most significant
	           / \
	          0   1
	         / \
	        1   0

	    sum = (101) + (100) + (11)
	        = (5)   + (4)   + (3)
	        = 12  
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
	int get_sum_of_paths() const;
private:
	shared_ptr<BinaryTreeNode<T> > d_root;
	void inorder_helper(const shared_ptr<BinaryTreeNode<T> >& node) const; 
	int get_sum_of_paths_helper(const shared_ptr<BinaryTreeNode<T> >& node, int sum_till_now) const;
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
int BinaryTree<T>::get_sum_of_paths_helper(const shared_ptr<BinaryTreeNode<T> >& node, int sum_till_now) const
{
	if(!node){
		return 0;
	}

	sum_till_now = 2 * sum_till_now + node->data;

	if(!node->left && !node->right){
		return sum_till_now;
	}

	return (this->get_sum_of_paths_helper(node->left, sum_till_now) + 
		    this->get_sum_of_paths_helper(node->right, sum_till_now));
}



template <typename T>
int BinaryTree<T>::get_sum_of_paths() const
{
	return this->get_sum_of_paths_helper(d_root, 0);
}

void test1()
{
	BinaryTree<int> t;
	shared_ptr<BinaryTreeNode<int> >& root = t.get_root();

	/*
	Construct a binary tree:
	            1  <-- Most significant
	           / \
	          0   1
	         / \
	        1   0
	Inorder: 1 0 0 1 1
	sum = (101) + (100) + (11)
	    = (5)   + (4)   + (3)
	    = 12  
	*/
	root = make_shared<BinaryTreeNode<int> >(1);
	root->left = make_shared<BinaryTreeNode<int> >(0);;
	root->right = make_shared<BinaryTreeNode<int> >(1);
	root->left->left = make_shared<BinaryTreeNode<int> >(1);
	root->left->right = make_shared<BinaryTreeNode<int> >(0);

	t.inorder();


	// Sum of paths 
	int sum_of_paths = t.get_sum_of_paths();

	cout << "sum_of_paths = " << sum_of_paths << endl;
}



int main()
{
	test1();

}