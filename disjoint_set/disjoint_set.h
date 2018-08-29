#ifndef DISJOINT_SET
#define DISJOINT_SET
#include <list>
#include <vector>
#include <iostream> //for display
struct Node
{
	int key;
};
class disjoint_set
{
	private:
		std::vector< std::list<Node> > rep;
	public:
		void make_set(int k);
		void make_set(Node mk);
		bool union_set(int x, int y);
		int find_set(int k);
		void display() const;
		void show_last() const;
};
#endif
