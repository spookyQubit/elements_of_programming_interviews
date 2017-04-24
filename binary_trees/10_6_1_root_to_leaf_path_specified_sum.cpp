#include <iostream>
#include <vector>
#include <memory>
#include <stack>

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
void specified_sum_root_to_leaf_path_helper(const shared_ptr<BinaryTreeNode<T> > node, 
	                                                      const T& v, 
	                                                      stack<T> s, 
	                                                      vector<stack<T> >& paths,
	                                                      T partial_sum)
{
	if(!node){
		return;
	}

	partial_sum = partial_sum + node->data;
	s.push(node->data);

	if(!node->left && !node->right){
		// This is a leaf
		if(partial_sum == v){
			// This path needs to be recorded 
			paths.emplace_back(s);
		}
	}

	specified_sum_root_to_leaf_path_helper(node->left, v, s, paths, partial_sum);
	specified_sum_root_to_leaf_path_helper(node->right, v, s, paths, partial_sum);
}



template <typename T>
vector<stack<T> > specified_sum_root_to_leaf_path(const shared_ptr<BinaryTreeNode<T> > root, const T& v)
{
	vector<stack<T> > paths;
	stack<T> s;
	specified_sum_root_to_leaf_path_helper(root, v, s, paths, 0);

	return paths;
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
	      6   2  7   1 
	                  \
	                   6 
	                  
	                  
	Inorder: 6 25 2 10 7 20 1 6
 
	*/

	root = make_shared<BinaryTreeNode<int> >(10);
	root->left = make_shared<BinaryTreeNode<int> >(25);
	root->right = make_shared<BinaryTreeNode<int> >(20);
	root->left->right = make_shared<BinaryTreeNode<int> >(2);
	root->left->left = make_shared<BinaryTreeNode<int> >(6);
	root->right->left = make_shared<BinaryTreeNode<int> >(7);
	root->right->right = make_shared<BinaryTreeNode<int> >(1);
	root->right->right->right = make_shared<BinaryTreeNode<int> >(6);

	t.inorder();

	// Get whether there is a leaf in t such that the sum of root to the leaf has a specified sum. 
	//cout << "has_specified_root_to_leaf_sum = " 
	//     << specified_sum_root_to_leaf_path<int>(root, 37)
	//     << endl;

	vector<stack<int> > paths = specified_sum_root_to_leaf_path<int>(root, 37);

	for(int i=0; i<paths.size(); ++i)
	{
		cout << "path " << i << endl;
		stack<int> path = paths[i];
		while(!path.empty()){
			cout << path.top() << " ";
			path.pop();
		}
		cout << endl;
	}
}

int main()
{
	test1();
}