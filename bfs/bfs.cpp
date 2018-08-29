#include "graph.h"
#include <queue>
#include <iostream> //for show functions
Graph::Graph(int v)
{
	vertex_count = v;
	v_list = new vertex [vertex_count];
	for(int i = 0; i < vertex_count; i++) 
	{
		v_list[i].key = i;
	}
}
Graph::~Graph()
{
	delete [] v_list;
}
void Graph::addEdge(int u, int v)
{
	v_list[u].adj.push_back(&v_list[v]);
	v_list[v].adj.push_back(&v_list[u]);
}
void Graph::BFS(int src_key)
{
	vertex* u;
	vertex* v;
	std::queue<vertex*> q;
	for(int i = 0; i < vertex_count; i++) 
	{
		v_list[i].d = 0;
		v_list[i].p = 0;
	}
	for(int i = 0; i < vertex_count; i++)
	{
		if(src_key == v_list[i].key) 
		{
			u = &v_list[i];
			break;
		}
	}
	q.push(u);
	while(!q.empty())
	{
		u = q.front();
		q.pop();
		for(int i = 0; i < u->adj.size(); i++)
		{
			v = u->adj[i];
			if(v->p == 0 && v->key != src_key)
			{
				v->p = u;
				v->d = u->d + 1;
				q.push(v);
			}
		}
	}
}
void Graph::show_adj() const
{
	for(int i = 0; i < vertex_count; i++)
	{
		std::cout<<i<<" : ";
		for(int j = 0; j < v_list[i].adj.size(); j++)
		{
			std::cout<<v_list[i].adj[j]->key<<"->";
		}
		std::cout<<"NULL"<<std::endl;
	}
}
void Graph::show_d() const
{
	for(int i = 0; i < vertex_count; i++)
	{
		std::cout<<i<<"'s d : "<<v_list[i].d<<std::endl;
	}
}
void Graph::show_p() const
{
	for(int i = 0; i < vertex_count; i++)
	{
		v_list[i].p != 0 ? std::cout<<i<<"'s p : "<<v_list[i].p->key<<std::endl : std::cout<<i<<"'s p : "<<0<<std::endl;
	}
}
