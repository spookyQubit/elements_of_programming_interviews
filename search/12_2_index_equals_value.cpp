#include <iostream>
#include <vector>


using namespace std;

/*
Purpose: Given a sorted array A, find all indices i, such that A[i] = i.
*/


void get_indices_equals_value_helper(vector<int> *pt_result, const vector<int>& v, int l, int r)
{
	if(l > r  || 
		l < 0 || 
		r >= v.size()){
		return;
	}

	int mid = l + (r - l)/2;
	if(v[mid] == mid){
		pt_result->push_back(mid);
		get_indices_equals_value_helper(pt_result, v, mid+1, r);
		get_indices_equals_value_helper(pt_result, v, l, mid - 1);
	}else if(v[mid] > mid){
		// We cannot have any i > mid such that v[i] = i
		// So restrict the search to the left of mid
		get_indices_equals_value_helper(pt_result, v, l, mid - 1);
	} else // v[mid] < mid
	{
		// We cannot have any i < mid such that v[i] = i
		// So restrict the search to the right of mid
		get_indices_equals_value_helper(pt_result, v, mid + 1, r);
	}

}


vector<int> get_indices_equals_value(const vector<int>& v)
{
	vector<int> result;
	get_indices_equals_value_helper(&result, v, 0, v.size() - 1);
	return result;
}

void test1()
{
	vector<int> v = {-2, -1, 0, 2, 4, 5, 6, 10};
	vector<int> result = get_indices_equals_value(v);

	for(int i = 0; i < result.size(); ++i)
	{
		cout << "result[i] = " << result[i]
		     << endl;
	}
}

int main()
{
	test1();
}