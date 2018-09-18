#include "bst.h"
#include <iostream>
int main()
{
	BST b;
	b.bst_insert({3});
	b.bst_insert({5});
	b.bst_insert({2});
	b.bst_insert({1});
	b.bst_insert({4});
	b.bst_insert({6});
	b.postorder_traversal(*b.bst_search({3}));
}
