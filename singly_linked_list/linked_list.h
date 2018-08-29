#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include <iostream> //for display
struct NODE
{
	int key;
	NODE* next;
};
class linked_list
{
	private:
		NODE* HEAD;
		int SIZE;
	public:
		linked_list();
		bool insert_after(NODE node, NODE new_node);
		void insert_beginning(NODE new_node);
		bool remove_after(NODE node);
		bool remove_beginning();
		void display() const;
		inline int size() const {return SIZE;}
};
#endif
