#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

/*
Purpose: Implement LRU cache
The three operations which we need to implement are: Insert, lookup and delete. 
We will have a unordered_map called hash_table for fast lookup.
We will have a list (double link list) called lru_queue to store how recent an key which is looked up.  
The hash_table will store (key and reference to key in queue ) 
We will have a list (double link list) to store
*/


template <typename T>
class LRU
{
private:
	typedef typename list<T>::iterator t_QUEUE_ITERATOR;
	
	int d_capacity;
	list<T> d_lru_queue;
	unordered_map<T, t_QUEUE_ITERATOR> d_hash_table;
public:
	LRU(int _capacity) : d_capacity(_capacity) {}
	void insert(const T& key);
	bool lookup(const T& key); // returns whether it exists or not
	bool del(const T& key);

	void print() const;
};

template <typename T>
void LRU<T>::insert(const T& key)
{
	if(d_hash_table.find(key) != d_hash_table.end()){
		d_lru_queue.erase(d_hash_table[key]);
		d_hash_table.erase(key);
	}

	if(d_lru_queue.size() >= d_capacity){
		// Remove the oldest entry
		const T& oldest_key = d_lru_queue.back();
		d_lru_queue.erase(d_hash_table[oldest_key]);
		d_hash_table.erase(oldest_key);
	}

	d_lru_queue.push_front(key);
    d_hash_table.emplace(key, d_lru_queue.begin());
}

template <typename T>
bool LRU<T>::lookup(const T& key)
{
	if(d_hash_table.find(key) == d_hash_table.end()){
		return false;
	}

	// The key exists
	// Update the position of the key in the queue and return true
	d_lru_queue.erase(d_hash_table[key]);
	d_hash_table.erase(key);

	d_lru_queue.push_front(key);
    d_hash_table.emplace(key, d_lru_queue.begin());

	return true;
}

template <typename T>
bool LRU<T>::del(const T& key)
{
	if(d_hash_table.find(key) == d_hash_table.end()){
		return false;
	}

	// The key exists
	d_lru_queue.erase(d_hash_table[key]);
	d_hash_table.erase(key);

	return true;
}

template <typename T>
void LRU<T>::print() const
{
	for(auto it = d_lru_queue.begin(); it != d_lru_queue.end(); ++it)
	{
		cout << *it << " ";
	}

	cout << endl;

	cout << "size = " << d_lru_queue.size() << endl;
}

void test1()
{
	LRU<int> lru_cache(3);

	lru_cache.insert(12);
	lru_cache.insert(13);
	lru_cache.insert(12);
	lru_cache.insert(11);
	lru_cache.insert(12);
	lru_cache.insert(12);
	lru_cache.insert(14);

	lru_cache.del(12);
	lru_cache.print();

}


int main()
{
	test1();
}
