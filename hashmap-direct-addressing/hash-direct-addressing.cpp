#include "hash.h"
hashmap_direct::hashmap_direct(int u)
{
	this->u = u;
	v.resize(u);
	for(int i = 0; i < v.size(); i++)
	{
		v[i].key = -1;
	}
}
bool hashmap_direct::insert(element& e)
{
	if(v[e.key].key != -1) 
	{
		return false;
	}
	else
	{
		v[e.key] = e;
		return true;
	}	
}
bool hashmap_direct::remove(int k)
{
	if(v[k].key == -1)
	{
		return false;
	}
	else
	{
		v[k].key = -1;
		return true;
	}
}
element& hashmap_direct::search(int k)
{
	return v[k];
}
