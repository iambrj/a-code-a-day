#include "graph.h"
#include <iostream>
using namespace std;
int main()
{
	Graph g(6);
	g.addEdge(0,1);
	g.addEdge(0,5);
	g.addEdge(1,4);
	g.addEdge(2,3);
	g.addEdge(2,4);
	g.addEdge(3,3);
	g.addEdge(4,5);
	g.addEdge(5,1);
	g.show_adj();
	g.DFS();
	g.show_times();
	g.show_p();
}
