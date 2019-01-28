#ifndef _AVL_H_
#define _AVL_H_
#include <iostream> // for cout in traversal
#include <cstdlib> // for abs
#include <algorithm> // for max
using namespace std;
struct NODE
{
	int key;
	int h;
	NODE *l, *r, *p;
};
class AVL
{
	private:
		NODE* ROOT;
	public:
		AVL();
		bool insert(NODE n);
		bool remove(int k);
		NODE* search(int k);
		void update_height(NODE* n);
		void right_rotate(int k);
		void left_rotate(int k);
		void inorder_traversal(NODE& n) const;
		void postorder_traversal(NODE& n) const;
		inline int max(int a, int b) {return a < b ? a : b;}
};
#endif
