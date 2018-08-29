#ifndef _GRAPH_H_
#define _GRAPH_H_
#include <vector>
struct vertex
{
	int key;
	int time_d, time_f;
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
		void DFS();
		void DFS_recursive(vertex* d, int& time);
		void show_adj() const;
		void show_times() const;
		void show_p() const;
};
#endif
