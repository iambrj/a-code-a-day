#ifndef _GRAPH_H_
#define _GRAPH_H_
#include <vector>
struct vertex
{
	int key;
	int d;
	vertex* p;
	std::vector<vertex*> adj;
};
class Graph
{
	private:
		int vertex_count;
		vertex* v_list;
	public:
		Graph(int v = 0);
		~Graph();
		void addEdge(int u, int v);
		void BFS(int source);
		void show_adj() const;
		void show_d() const;
		void show_p() const;
};
#endif
