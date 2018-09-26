#include "hash-chain.h"
hashmap_chain::hashmap_chain(int u)
{
	this->u = u;
	v.resize(u);
}
bool hashmap_chain::insert(element& e)
{
	v[e.key].push_back(e);
	return true;
}
bool hashmap_chain::remove(int k)
{
	if(v[k].size() == 0)
	{
		return false;
	}
	else
	{
		v[k].pop_front();
		return true;
	}
}
element& hashmap_chain::search(int k)
{
	return v[k].front();
}
