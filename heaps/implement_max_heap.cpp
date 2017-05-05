#include <iostream>
#include <vector>


using namespace std;

/*
Purpose: Make a priority queue using a vector. 

*/

class max_heap{
public:
	void push(int v);
	int top() const;
	void pop();
	inline int size() const { return d_h.size(); }
	void print_heap() const;
private:
	vector<int> d_h;
	int get_parent(int current_index) const;
	pair<int, int> get_child_indexes(int current_index) const;
	int get_index_of_bigger_child(int current_index) const;
};

void max_heap::print_heap() const
{
	for(int i=0; i < d_h.size(); ++i)
	{
		cout << d_h[i] << " ";
	}

	cout << endl;
}

int max_heap::get_parent(int current_index) const
{
	int parent;
	if(current_index % 2 == 0){
		parent = current_index / 2 - 1;
	}else{
		parent = current_index / 2;
	}

	return parent;
}

pair<int,int> max_heap::get_child_indexes(int current_index) const
{
	int left = current_index * 2 + 1;
	int right = current_index * 2 + 2;
	pair<int, int> child_indexes(left, right);

	return child_indexes;
}

int max_heap::get_index_of_bigger_child(int current_index) const
{
	pair<int, int> child_indexes = get_child_indexes(current_index);

	if(child_indexes.first >= d_h.size() && child_indexes.second >= d_h.size()){
		return current_index;
	}

	if(child_indexes.first >= d_h.size()){
		return child_indexes.second;

	}

	if(child_indexes.second >= d_h.size()){
		return child_indexes.first;

	}

	int max_index = d_h[child_indexes.first] > d_h[child_indexes.second] ? child_indexes.first : child_indexes.second;
	return max_index;
}

void max_heap::push(int v)
{
	d_h.emplace_back(v);
	
	int current_index = d_h.size() - 1;
	int parent_index = get_parent(current_index);
	while(parent_index >= 0 && d_h[parent_index] < d_h[current_index]){
		swap(d_h[parent_index], d_h[current_index]);
		
		current_index = parent_index;
		parent_index = get_parent(current_index);
	}
	
}

int max_heap::top() const
{
	if(d_h.size() > 0){
		return d_h[0];
	}else{
		throw length_error("Empty");
	}
}

void max_heap::pop()
{
	if(d_h.size() == 0){
		throw length_error("Empty");
	}

	int ret = d_h[0];
	d_h[0] = d_h[d_h.size() - 1];
	
	int current_index = 0;
	int index_of_bigger_child = get_index_of_bigger_child(current_index);
	
	while(d_h[current_index] < d_h[index_of_bigger_child]){
		swap(d_h[current_index], d_h[index_of_bigger_child]);

		current_index = index_of_bigger_child;
		index_of_bigger_child = get_index_of_bigger_child(current_index);
	}

	d_h.pop_back();
}

int main()
{
	max_heap h;
	h.push(10);
	h.push(20);
	h.push(5);
	h.push(30);
	h.push(25);


	h.print_heap();

	h.pop();
	h.print_heap();

	h.pop();
	h.print_heap();
}