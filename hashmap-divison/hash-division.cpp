#include "hash-division.h"
hashmap_division::hashmap_division(int size)
{
	this->size = size;
	v.resize(size);
}
bool hashmap_division::insert(element& e)
{
	v[e.key % this->size].push_back(e);
	return true;
}
bool hashmap_division::remove(int k)
{
	if(v[k % this->size].size() == 0)
	{
		return false;
	}
	else
	{
		v[k % this->size].pop_front();
		return true;
	}
}
element& hashmap_division::search(int k)
{
	return v[k % size].front();
}
