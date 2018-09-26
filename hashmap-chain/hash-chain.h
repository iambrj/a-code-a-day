#ifndef _HASH_CHAIN_H_
#define _HASH_CHAIN_H_
#include <vector>
#include <list>
struct element 
{
	int key;
};
class hashmap_chain
{
	private:
		std::vector < std::list <element> > v;
		int u; // u = universe of keys
	public:
		hashmap_chain(int u);
		bool insert(element& e);
		bool remove(int k);
		element& search(int k);
};
#endif
