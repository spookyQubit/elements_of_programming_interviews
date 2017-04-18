#include <iostream>
#include <memory>

using namespace std;

/*
Purpose: Check if the tree is balanced
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
	left = NULL;
	right = NULL;
	data = v;
}


template <class T>
class BinaryTree{
public:
	BinaryTree();
	inline shared_ptr<BinaryTreeNode<T> >& get_root() { return d_root; }
	void inorder() const;
	int height() const;
	bool is_balanced() const;
private:
	shared_ptr<BinaryTreeNode<T> > d_root;
	void inorder_helper(shared_ptr<BinaryTreeNode<T> > node) const;
	int height_helper(shared_ptr<BinaryTreeNode<T> > node) const;
	bool is_balanced_helper(shared_ptr<BinaryTreeNode<T> > node) const;
};


template <class T>
BinaryTree<T>::BinaryTree()
{
	d_root = NULL;
}

template <class T>
void BinaryTree<T>::inorder_helper(shared_ptr<BinaryTreeNode<T> > node) const
{
	if(!node){
		return;
	}

	this->inorder_helper(node->left);
	cout << node->data << endl;
	this->inorder_helper(node->right);

}

template <class T>
void BinaryTree<T>::inorder() const
{
	this->inorder_helper(d_root);
}


template <class T>
int BinaryTree<T>::height_helper(shared_ptr<BinaryTreeNode<T> > node) const
{
	if(!node){
		return 0;
	}

	return(1 + max(this->height_helper(node->left), this->height_helper(node->right)));
}

template <class T>
int BinaryTree<T>::height() const 
{
	return this->height_helper(d_root);
}


template <class T>
bool BinaryTree<T>::is_balanced_helper(shared_ptr<BinaryTreeNode<T> > node) const
{
	if(!node){
		return true;
	}

	if (abs(this->height_helper(node->left) - this->height_helper(node->right) > 1)){ 
		return false; 
	}
	else{ 
		return(is_balanced_helper(node->left) && is_balanced_helper(node->right)); 
	}  
}


template <class T>
bool BinaryTree<T>::is_balanced() const
{
	return this->is_balanced_helper(d_root);

}

int main()
{
	BinaryTree<int> t;
	shared_ptr<BinaryTreeNode<int> >& root = t.get_root();

	/*
	construct the tree:
	           10
	          /  \
	         20  30 
            / \    \ 
           5   3   35
          / \
         6   4 
    inorder: 6 4 5 20 3 10 30 35
    height: 4
    is_balanced = true 
	*/

	shared_ptr<BinaryTreeNode<int> > pt = make_shared<BinaryTreeNode<int> >(10);
	root = pt;

	pt = make_shared<BinaryTreeNode<int> >(20);
	root->left = pt;

	pt = make_shared<BinaryTreeNode<int> >(3);
	root->left->right = pt;

	pt = make_shared<BinaryTreeNode<int> >(30);
	root->right = pt;

	pt = make_shared<BinaryTreeNode<int> >(35);
	root->right->right = pt;

	pt = make_shared<BinaryTreeNode<int> >(5);
	root->left->left = pt;

	pt = make_shared<BinaryTreeNode<int> >(6);
	root->left->left->left = pt;

	pt = make_shared<BinaryTreeNode<int> >(4);
	root->left->left->right = pt;

	t.inorder();

	// get the height of the tree
	cout << "Height of the tree = " << t.height() << endl;

	cout << "is_balanced = " << t.is_balanced() << endl;

}