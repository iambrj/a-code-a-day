#include "disjoint_set.h"
void disjoint_set::show_last() const
{
	std::cout<<rep[0].end()->key<<std::endl;
}
void disjoint_set::make_set(Node mk)
{
	std::list<Node> l;
	l.push_back(mk);
	rep.push_back(l);
}
void disjoint_set::make_set(int k)
{
	Node n;
	n.key = k;
	disjoint_set::make_set(n);
}
int disjoint_set::find_set(int k)
{
	for(int i = 0; i < rep.size(); i++)
	{
		for(std::list<Node>::iterator itr = rep[i].begin(); itr != rep[i].end(); itr++)
		{
			if(itr->key == k)
			{
				itr = rep[i].begin();
				return itr->key;
			}
		}
	}
	return -1;
}
bool disjoint_set::union_set(int x, int y)
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
void disjoint_set::display() const
{
	for(int i = 0; i < rep.size(); i++)
	{
		for(std::list<Node>::const_iterator itr = rep[i].begin(); itr != rep[i].end(); itr++)
			std::cout<<itr->key<<"->";
		std::cout<<"NULL"<<std::endl;
	}
}
