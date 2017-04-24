#include <iostream>
#include <memory>
#include <stack>

using namespace std;
/*
Purpose: Given a binary tree, perform an inorder traversal without using recursion.
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
void inorder_without_recursion(const shared_ptr<BinaryTreeNode<T> >& root)
{
	stack<shared_ptr<BinaryTreeNode<T> > > s;
	shared_ptr<BinaryTreeNode<T> > current = root;

	while(current || !s.empty()){
		if(current){
			s.push(current);
			current = current->left;
		}else{
			cout << s.top()->data << endl;
			current = s.top()->right;
			s.pop();
		}
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

	
	root = make_shared<BinaryTreeNode<int> >(10);
	root->left = make_shared<BinaryTreeNode<int> >(25);
	root->right = make_shared<BinaryTreeNode<int> >(20);
	root->left->right = make_shared<BinaryTreeNode<int> >(5);
	root->left->left = make_shared<BinaryTreeNode<int> >(6);
	root->right->left = make_shared<BinaryTreeNode<int> >(7);
	root->right->right = make_shared<BinaryTreeNode<int> >(1);
	root->right->right->right = make_shared<BinaryTreeNode<int> >(6);
	root->right->right->right->left = make_shared<BinaryTreeNode<int> >(2);
	

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
	root->left = make_shared<BinaryTreeNode<int> >(25);
	root->right = make_shared<BinaryTreeNode<int> >(20);
	*/



	//t.inorder();

	// Inorder witout recursion
	inorder_without_recursion<int>(root);

}

int main()
{
	test1();
}