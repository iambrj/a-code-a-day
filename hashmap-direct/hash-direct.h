#ifndef _HASH_DIRECT_H_
#define _HASH_DIRECT_H_
#include <vector>
struct element 
{
	int key;
};
class hashmap_direct
{
	private:
		std::vector<element> v;
		int u; // u = universe of keys
	public:
		hashmap_direct(int u);
		bool insert(element& e);
		bool remove(int k);
		element& search(int k);
};
#endif
