#include <iostream>
#include <memory>
#include <vector>

using namespace std;

/*
Purpose: To find the lowest common ancestor of a node in a binary tree. 
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
	vector<T> get_path(const T& v) const;
	T get_common_ancestor(const T& v1, const T& v2) const; 
private:
	shared_ptr<BinaryTreeNode<T> > d_root;
	void inorder_helper(const shared_ptr<BinaryTreeNode<T> >& node) const;
	bool get_path_helper(vector<T>* pt_path, 
		                 const T& v, 
		                 const shared_ptr<BinaryTreeNode<T> > node) const;
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
bool BinaryTree<T>::get_path_helper(vector<T>* pt_path, 
	                                const T& v, 
	                                const shared_ptr<BinaryTreeNode<T> > node) const
{
	if(!node){
		return false;
	}

	cout << "node->data = " << node->data <<  endl;

	pt_path->push_back(node->data);

	if(node->data == v){
		return true;
	}

	if(this->get_path_helper(pt_path, v, node->left)){
		return true;
	} 

	if(this->get_path_helper(pt_path, v, node->right)){
		return true;
	}

	pt_path->pop_back();
	return false;
}

template <typename T>
vector<T> BinaryTree<T>::get_path(const T& v) const
{
	vector<T> path;
	this->get_path_helper(&path, v, d_root);
	for(int i = 0; i < path.size(); ++i){
		cout << i << "= " << path[i] << endl;
	}

	return path;
}

void get_path_case_1()
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
	path(7) --> 10, 20, 7
	*/
	shared_ptr<BinaryTreeNode<int> > pt = make_shared<BinaryTreeNode<int> >(10);
	root = pt;

	pt = make_shared<BinaryTreeNode<int> >(25);
	root->left = pt;

	pt = make_shared<BinaryTreeNode<int> >(20);
	root->right = pt;

	pt = make_shared<BinaryTreeNode<int> >(5);
	root->left->right = pt;

	pt = make_shared<BinaryTreeNode<int> >(6);
	root->left->left = pt;

	pt = make_shared<BinaryTreeNode<int> >(7);
	root->right->left = pt;

	pt = make_shared<BinaryTreeNode<int> >(1);
	root->right->right = pt;

	t.inorder();


	vector<int> path = t.get_path(7);
}


template <typename T>
T BinaryTree<T>::get_common_ancestor(const T& v1, const T& v2) const
{
	// Get the paths of each of the elements
	vector<T> path1 = this->get_path(v1);
	vector<T> path2 = this->get_path(v2);

	// iterate through the elements and return the last common element. 
	int l = min(path1.size(), path2.size());
	T temp;
	for(int i=0; i<l; ++i)
	{
		if(i==0){
			temp = path1[i];
			continue;
		}

		if(path1[i] != path2[i]){
			return temp;
		}

		temp = path1[i];
	}

	return path1[l - 1];
}


void get_common_ancestor_case_1()
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
	shared_ptr<BinaryTreeNode<int> > pt = make_shared<BinaryTreeNode<int> >(10);
	root = pt;

	pt = make_shared<BinaryTreeNode<int> >(25);
	root->left = pt;

	pt = make_shared<BinaryTreeNode<int> >(20);
	root->right = pt;

	pt = make_shared<BinaryTreeNode<int> >(5);
	root->left->right = pt;

	pt = make_shared<BinaryTreeNode<int> >(6);
	root->left->left = pt;

	pt = make_shared<BinaryTreeNode<int> >(7);
	root->right->left = pt;

	pt = make_shared<BinaryTreeNode<int> >(1);
	root->right->right = pt;

	t.inorder();

	int v1(6), v2(5);

	cout << "CommonAncestor(" 
	     << v1 
	     << ", " 
	     << v2 
	     << ") = " 
	     << t.get_common_ancestor(v1, v2) 
	     << endl;

	v1 = 20;
	v2 = 1;

	cout << "CommonAncestor(" 
	     << v1 
	     << ", " 
	     << v2 
	     << ") = " 
	     << t.get_common_ancestor(v1, v2) 
	     << endl;

}


int main()
{
	get_path_case_1();
	get_common_ancestor_case_1();
}