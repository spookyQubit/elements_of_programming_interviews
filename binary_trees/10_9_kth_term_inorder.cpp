#include <iostream>
#include <memory>
#include <stack>

using namespace std;
/*
Purpose: Given a binary tree, perform find the kth term in inorder traversal. 
Assume that each node contains how many nodes are rooted in that node.
*/

template <typename T>
struct BinaryTreeNode{
	BinaryTreeNode();
	BinaryTreeNode(const T& v, const int num_nodes);
	T data;
	int num_nodes;
	shared_ptr<BinaryTreeNode<T> > left;
	shared_ptr<BinaryTreeNode<T> > right;
};

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode()
{
	left = NULL;
	right = NULL;
	num_nodes = 0;
}

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(const T& v, const int n)
{
	data = v;
	left = NULL;
	right = NULL;
	num_nodes = n;
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
bool kth_node_inorder(T* pt_result, const shared_ptr<BinaryTreeNode<T> >& node, int k)
{
	if(!node){
		return false;
	}
	
	int current_node_order = node->left ? node->left->num_nodes + 1 : 1;
	cout << "current_node_order = " << current_node_order << endl;
	
	if(k == current_node_order){
		*pt_result = node->data;
		cout << "here" << endl;
		return true;
	}

	if(k > current_node_order){
		k = k - current_node_order;
		return kth_node_inorder(pt_result, node->right, k);
	}

	if(k < current_node_order){
		return kth_node_inorder(pt_result, node->left, k);
	}
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
	*/

	
	/*
	root = make_shared<BinaryTreeNode<int> >(10, 9);
	root->left = make_shared<BinaryTreeNode<int> >(25, 3);
	root->right = make_shared<BinaryTreeNode<int> >(20, 5);
	root->left->right = make_shared<BinaryTreeNode<int> >(5, 1);
	root->left->left = make_shared<BinaryTreeNode<int> >(6, 1);
	root->right->left = make_shared<BinaryTreeNode<int> >(7, 1);
	root->right->right = make_shared<BinaryTreeNode<int> >(1, 3);
	root->right->right->right = make_shared<BinaryTreeNode<int> >(6, 1);
	root->right->right->right->left = make_shared<BinaryTreeNode<int> >(2, 1);
	*/
	

	/*
	Construct a binary tree:
	           10
	          /  \
	         /    \
	        25    20 
	Inorder: 25 10 20
	*/

	
	root = make_shared<BinaryTreeNode<int> >(10, 3);
	root->left = make_shared<BinaryTreeNode<int> >(25, 1);
	root->right = make_shared<BinaryTreeNode<int> >(20, 1);

	t.inorder();

	// kth node in inorder
	int k = 4;
	int result;
	if(kth_node_inorder<int>(&result, root, k)){
		cout << "kth inorder element = " << result << endl;
	}else{
		cout << "Not here" << endl;

	}

}

int main()
{
	test1();
}