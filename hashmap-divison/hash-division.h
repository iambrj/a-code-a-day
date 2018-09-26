#ifndef _HASH_DIVISION_H_
#define _HASH_DIVISION_H_
#include <vector>
#include <list>
struct element 
{
	int key;
};
class hashmap_division
{
	private:
		std::vector < std::list <element> > v;
		int size; // size = size of hashmap
	public:
		hashmap_division(int size);
		bool insert(element& e);
		bool remove(int k);
		element& search(int k);
};
#endif
