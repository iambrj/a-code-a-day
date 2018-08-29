//TODO: write a iterative version 
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
}
void Graph::DFS()
{
	for(int i = 0; i < vertex_count; i++)
	{
		v_list[i].p = 0;
		v_list[i].time_d = 0;
		v_list[i].time_f = 0;
	}
	int time = 0;
	for(int i = 0; i < vertex_count; i++)
	{
		if(v_list[i].p == 0)
		{
			DFS_recursive(&v_list[i], time);
		}
	}
}
void Graph::DFS_recursive(vertex* d, int& time)
{
	d->time_d = ++time;
	vertex* v;
	for(int i = 0; i < d->adj.size(); i++)
	{
		v = d->adj[i];
		if(v->p == 0)
		{
			v->p = d;
			DFS_recursive(v,time);
		}
	}
	d->time_f = ++time;
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
void Graph::show_times() const
{
	for(int i = 0; i < vertex_count; i++)
	{
		std::cout<<i<<"'s time_d : "<<v_list[i].time_d<<std::endl;
		std::cout<<i<<"'s time_f : "<<v_list[i].time_f<<std::endl;
	}
}
void Graph::show_p() const
{
	for(int i = 0; i < vertex_count; i++)
	{
		v_list[i].p != 0 ? std::cout<<i<<"'s p : "<<v_list[i].p->key<<std::endl : std::cout<<i<<"'s p : "<<0<<std::endl;
	}
}
