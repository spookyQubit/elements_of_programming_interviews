#include <iostream>
#include <memory>
#include <stack>
#include <vector>
#include <assert.h>

using namespace std;
/*
Purpose: Given an array A  = [2, 1, 4, 8, 3, 2, 9, 10, 0]
         Construct a binary tree for which the root is the max of A. 
         The left child of root is the max of A[0, m] where A[m] = max(A)
         The right child of root is the max of A[m+1, n-1]
         MaxTree(A) =

                   10
                  /  \
                 9    0
                / 
               8
              / \
             4   3
            / \   \
           2   1   2
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
int get_max_id(const vector<T>& a, int left, int right)
{
	if(left > right || 
		left < 0 || 
		right >= a.size() || 
		right < 0 || 
		left > a.size()){

		return -1;
	}

	int max_id = left;
	T max_till_now = a[left];

	for(int i=left+1; i<=right; ++i){

		max_id = a[i] > max_till_now ? i : max_id; 
	}

	return max_id;
}

template <typename T>
shared_ptr<BinaryTreeNode<T> > get_max_tree_root_helper(const vector<T>& a, int left, int right)
{
	int max_id = get_max_id<int>(a, left, right);
	if(max_id < 0){
		return NULL;
	}

	shared_ptr<BinaryTreeNode<T> > root;
	root = make_shared<BinaryTreeNode<T> >(a[max_id]);

	root->left = get_max_tree_root_helper(a, left, max_id - 1);
	root->right = get_max_tree_root_helper(a, max_id + 1, right);

	return root;
}

template <typename T>
shared_ptr<BinaryTreeNode<T> > get_max_tree_root(const vector<T>& a)
{
	return get_max_tree_root_helper(a, 0, a.size() - 1);
}

void test1()
{
	/*
	A  = [2, 1, 4, 8, 3, 2, 9, 10, 0]

	MaxTree(A) =

                   10
                  /  \
                 9    0
                / 
               8
              / \
             4   3
            /     \
           2       2
            \
	         1
	*/
	vector<int> a = {2, 1, 4, 8, 3, 2, 9, 10, 0};
	BinaryTree<int> t; 
	shared_ptr<BinaryTreeNode<int> >& root = t.get_root();
	root = get_max_tree_root(a);

	t.inorder();
}

int main()
{
	test1();
}