#include "avl.h"
int main()
{
	AVL a;
	a.insert({3});
	a.insert({2});
	a.insert({5});
	a.insert({4});
	a.insert({1});
	a.insert({6});
	a.insert({7});
	a.insert({8});
	a.inorder_traversal(*(a.search(3)));
}
