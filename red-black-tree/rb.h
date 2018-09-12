#ifndef _RB_H_ //protection from multiple inclusion
#define _RB_H_
#include <iostream>
using namespace std;
struct NODE
{
	int key;
	int color; //black = 0 and red = 1
	NODE* p; //pointer to parent
	NODE* r; //pointer to right child
	NODE* l; //pointer to left child
};
class RBT
{
	private:
		NODE* ROOT;
	public:
		NODE* root() {return ROOT;}
		RBT();
		NODE* search(int k) const; // return pointer to node with key k
		NODE* minimum(NODE& n) const; // return pointer to minimum node in subtree rooted at n
		bool insert_node(int k); //returns true if successful, false otherwise.
		void transplant(NODE* u, NODE* v);
		bool delete_node(int k); //true if successful, false otherwise.
		void left_rotate(int k);
		void right_rotate(int k);
};
#endif
