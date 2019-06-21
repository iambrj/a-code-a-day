#include "disjoint_set.h"
typename T
void disjoint_set::make_set(T k)
{
	Node n;
	n.key = k;
	n.parent = &n;
	roots.push_back(n);
}
typename T
Node& disjoint_set::find_set(T k)
{
	if()
}
typename T
bool disjoint_set::union_set(T x, T y)
{
	int i, j;
	for(i = 0; i < rep.size(); i++)
	{
		if(rep[i].front().key == x)
			break;
	}
	for(j = 0; j < rep.size(); j++)
	{
		if(rep[j].front().key == y)
			break;
	}
	if(i == rep.size() || j == rep.size()) return false;
	if(rep[i].size() < rep[j].size())
	{
		rep[j].splice(rep[j].end(),rep[i],rep[i].begin(),rep[i].end());
		std::vector< std::list<Node> >::const_iterator itr = rep.begin() + i;
		rep.erase(itr);
	}
	else
	{
		rep[i].splice(rep[i].end(),rep[j],rep[j].begin(),rep[j].end());
		std::vector< std::list<Node> >::const_iterator itr = rep.begin() + j;
		rep.erase(itr);
	}
	return true;
}
