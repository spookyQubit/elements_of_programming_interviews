#include <iostream>
#include <memory>
#include <stack>
#include <vector>
#include <assert.h>

using namespace std;
/*
Purpose: Given the preorder and inorder traversals, construct the binary tree. 
         Assume that the tree has unique elements.
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
int get_inorder_idx(const T& v, const vector<T>& inorder)
{
	for(int i=0; i<inorder.size(); ++i)
	{
		if(inorder[i] == v){
			return i;
		}
	}

	return -1;

}

template <typename T>
shared_ptr<BinaryTreeNode<T> > get_tree_root_helper(const vector<T>& inorder, 
	                                                int inorder_left, 
	                                                int inorder_right, 
	                                                const vector<T>& preorder, 
	                                                int preorder_left, 
	                                                int preorder_right)
{
	shared_ptr<BinaryTreeNode<T> > root = NULL;

	if(preorder.size() == 0 || inorder.size() == 0){
		return root;
	}

	if(inorder_left < 0 || preorder_left < 0){
		return root;
	}

	if(inorder_right > inorder.size() || preorder_left > preorder.size()){
		return root;
	}

	if(inorder_right < inorder_left || preorder_right < inorder_left){
		return root;
	}

	// The root is the first element in the preorder array
	root = make_shared<BinaryTreeNode<T> >(preorder[preorder_left]);
	cout << "root->data = " << root->data << endl;
	
	// The idx in the inorder vector splits the tree in left and right
	int inorder_idx = get_inorder_idx<T>(preorder[preorder_left], inorder);
	int left_tree_size = inorder_idx - inorder_left;
	int right_tree_size = inorder_right - inorder_idx;

	// The left subtree is created with the left part of the inorder array
	root->left = get_tree_root_helper<T>(inorder, inorder_left, inorder_idx - 1, // what if -1
		                              preorder, preorder_left + 1, preorder_left + left_tree_size);

	// The right subtree is created with the right part of the inorder array
	root->right = get_tree_root_helper<T>(inorder, inorder_idx + 1, inorder_right, // what if -1
		                               preorder, preorder_right - right_tree_size + 1, preorder_right);
	return root;

}

template <typename T>
shared_ptr<BinaryTreeNode<T> > get_tree_root(const vector<T>& inorder, const vector<T>& preorder)
{
	return get_tree_root_helper(inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() - 1);
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
	                   6  <--- Duplication is not allowed!!! Incorrect input.
 	                  /
	                 2 
	Inorder: 6 25 5 10 7 20 1 2 6
	Preorder: 10 25 6 5 20 7 1 6 2
	Postorder: 6 5 25 7 2 6 1 20 10
	*/

	/*
	root = make_shared<BinaryTreeNode<int> >(10);
	root->left = make_shared<BinaryTreeNode<int> >(25);
	root->right = make_shared<BinaryTreeNode<int> >(20);
	root->left->right = make_shared<BinaryTreeNode<int> >(5);
	root->left->left = make_shared<BinaryTreeNode<int> >(6);
	root->right->left = make_shared<BinaryTreeNode<int> >(7);
	root->right->right = make_shared<BinaryTreeNode<int> >(1);
	root->right->right->right = make_shared<BinaryTreeNode<int> >(6);
	root->right->right->right->left = make_shared<BinaryTreeNode<int> >(2);
	*/
	
	

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
	*/


	
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




	// Reconstruct
	//vector<int> inorder =  {6, 25, 5, 10, 7, 20, 1, 2, 6};
	//vector<int> preorder = {10, 25, 6, 5, 20, 7, 1, 6, 2};

	vector<int> inorder =  {6, 25, 5, 10, 7, 20, 1, 9};
	vector<int> preorder = {10, 25, 6, 5, 20, 7, 1, 9};

	BinaryTree<int> t_reconstructed; 
	shared_ptr<BinaryTreeNode<int> >& reconstructed_tree_root = t_reconstructed.get_root();
	reconstructed_tree_root = get_tree_root<int>(inorder, preorder);

	cout << "reconstructing " << endl;
	t_reconstructed.inorder();
}

int main()
{
	test1();
}