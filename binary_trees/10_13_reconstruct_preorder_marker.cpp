#include <iostream>
#include <memory>
#include <stack>
#include <vector>
#include <assert.h>

using namespace std;
/*
Purpose: Given the preorder traversals with markers, reconstruct the binary tree. 
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
shared_ptr<BinaryTreeNode<T> > get_tree_root_helper(int& current_idx, 
	                                   const vector<T>& preorder, 
	                                   const T& null_marker) // Important to have it as refernce.
{
	if(preorder[current_idx] == null_marker){
		return NULL;
	}

	shared_ptr<BinaryTreeNode<T> > root = make_shared<BinaryTreeNode<T> >(preorder[current_idx]);
	root->left = get_tree_root_helper(++current_idx, preorder, null_marker);
	root->right = get_tree_root_helper(++current_idx, preorder, null_marker);

	return root;
}

template <typename T>
shared_ptr<BinaryTreeNode<T> > get_tree_root(const vector<T>& preorder, const T& null_marker)
{
	int current_idx = 0;
	return get_tree_root_helper(current_idx, preorder, null_marker);
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
	Preorder with marker: 10 25 6 NULL NULL 5 NULL NULL 20 7 NULL NULL 1 NULL 9 NULL NULL
	In the following, assume that the marker is given by -1.
	*/
	
	/*
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

	cout << "preorder" << endl;
	t.preorder();

	cout << "postorder" << endl;
	t.postorder();
	*/

	// Reconstruct
	int null_marker = -1;
	vector<int> preorder = {10, 25, 6, 
		                    null_marker, null_marker, 5, 
		                    null_marker, null_marker, 20, 
		                    7, null_marker, null_marker, 
		                    1, null_marker, 9, 
		                    null_marker, null_marker};
    BinaryTree<int> t_reconstructed;
    shared_ptr<BinaryTreeNode<int> >& root = t_reconstructed.get_root();
    root = get_tree_root<int>(preorder, null_marker);
    cout << "reconstruct" << endl;

    t_reconstructed.inorder();

}

int main()
{
	test1();
}