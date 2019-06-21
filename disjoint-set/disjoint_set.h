#ifndef DISJOINT_SET
#define DISJOINT_SET
#include <vector>
#include <iostream> //for display
typename T
class Node
{
	public:
		T key;
		Node* parent;
};
typename T
class disjoint_set
{
	private:
		vector<Node> parents;
	public:
		disjoint_set(): count(0) {};
		void make_set(T mk);
		bool union_set(T x, T y);
		Node& find_set(T k);
		int get_count() const { return roots.size(); }
};
#endif
