#include <iostream>
#include <memory>
#include <vector>
#include <map>

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
void get_leaves_and_child_parents(shared_ptr<BinaryTreeNode<T> > node, 
	                              vector<shared_ptr<BinaryTreeNode<int> > > *pt_leaves, 
	                              map<shared_ptr<BinaryTreeNode<int> >, shared_ptr<BinaryTreeNode<int> > > *pt_c_p)
{
	if(!node){
		return;
	}

	get_leaves_and_child_parents(node->left, pt_leaves, pt_c_p);
	if(!node->left && !node->right){
		// This is a leaf
		pt_leaves->emplace_back(node);
	}
	if(!node->left){
		pt_c_p->emplace(node->left, node);
	}
	if(!node->right){
		pt_c_p->emplace(node->right, node);
	}
	get_leaves_and_child_parents(node->right, pt_leaves, pt_c_p);
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
	Inorder: 6 25 5 10 7 20 1
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

	t.inorder();

	// Get all leaves and the map containing the child: parent mapping
	vector<shared_ptr<BinaryTreeNode<int> > > leaves;
	map<shared_ptr<BinaryTreeNode<int> >, shared_ptr<BinaryTreeNode<int> > > child_parent;
	get_leaves_and_child_parents<int>(root, &leaves, &child_parent);
}



int main()
{
	test1();

}