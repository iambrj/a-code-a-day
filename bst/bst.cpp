#include "bst.h"
#include <iostream>
NODE BST_NULL = {-1,0,0,0}; //sentinal
BST::BST()
{
	ROOT = 0;
}
NODE* BST::bst_search(const NODE& x) const
{
	if(ROOT == 0) return &BST_NULL;
	NODE* curr = ROOT;
	for(;;)
	{
		if(x.key == curr->key) return curr;
		else if(x.key < curr->key)
		{
			if(curr->l == 0) return &BST_NULL;
			else curr = curr->l;
		}
		else
		{
			if(curr->r == 0) return &BST_NULL;
			else curr = curr->r;
		}
	}
}
NODE* BST::bst_successor(const int k) const
{
	if(ROOT == 0) return &BST_NULL;
	NODE* x = bst_search({k});
	if(x->r != 0) return bst_min(*x->r);
	NODE* y = x->p;
	while(y != 0 && x == y->r)
	{
		x = y;
		y = y->p;
	}
	if(y == 0) return &BST_NULL;
	else return y;
}
NODE* BST::bst_predecessor(const int k) const
{
	if(ROOT == 0) return &BST_NULL;
	NODE* x = bst_search({k});
	if(x->l != 0) return bst_min(*x->l);
	NODE* y = x->p;
	while(y != 0 && x == y->l)
	{
		x = y;
		y = y->p;
	}
	if(y == 0) return &BST_NULL;
	else return y;
}
bool BST::bst_insert(const NODE& n)
{
	NODE* insert = new NODE;
	insert->l = 0;
	insert->r = 0;
	insert->p = 0;
	insert->key = n.key;
	if(ROOT == 0)
	{
		ROOT = insert;
		return true;
	}
	NODE* curr = ROOT;
	for(;;)
	{
		if(insert->key < curr->key)
		{
			if(curr->l == 0)
			{
				curr->l = insert;
				insert->p = curr;
				return true;
			}
			else curr = curr->l;
		}
		else if(insert->key > curr->key)
		{
			if(curr->r == 0)
			{
				curr->r = insert;
				insert->p = curr;
				return true;
			}
			else curr = curr->r;
		}
	}
	return false;
}
bool BST::bst_delete(const int k)
{
	if(ROOT == 0) return false;
	NODE* z = bst_search({k});
	if(z->key == -1) return false;
	if(z->l == 0 && z->r == 0) //no child
	{
		if(z->p->r == z) z->p->r = 0;
		else z->p->l = 0;
		delete z;
		return true;
	}
	if(z->l == 0 && z->r != 0) //only left child
	{
		if(z->p->r == z) 
		{
			z->p->r = z->r;
			z->r->p = z->p;
			delete z;
			return true;
		}
		else if(z->p->l == z)
		{
			z->p->l = z->r;
			z->r->p = z->p;
			delete z;
			return true;
		}
	}
	else if(z->r == 0 && z->l != 0) //only right child
	{
		if(z->p->r == z) 
		{
			z->p->r = z->l;
			z->l->p = z->p;
			delete z;
			return true;
		}
		else if(z->p->l == z)
		{
			z->p->l = z->l;
			z->l->p = z->p;
			delete z;
			return true;
		}
	}
	else //both children
	{
		NODE* succ = z->r;
		while(succ->l != 0) succ = succ->l;
		bst_delete(succ->key);
		return true;
	}
	return false;
};
NODE* BST::bst_min(const int k) const
{
	NODE* min = ROOT;
	for(;;)
	{
		if(k == min->key) break;
		else if(k < min->key) min = min->l;
		else min = min->r;
	}
	while(min->l != 0) min = min->l;
	return min;
}
NODE* BST::bst_max(const int k) const
{
	NODE* min = ROOT;
	for(;;)
	{
		if(k == min->key) break;
		else if(k < min->key) min = min->l;
		else min = min->r;
	}
	while(min->r != 0) min = min->r;
	return min;
}
NODE* BST::bst_min(NODE& n) const
{
	NODE* min = &n;
	while(min->l != 0) min = min->l;
	return min;
}
NODE* BST::bst_max(NODE& n) const
{
	NODE* max = &n;
	while(max->r != 0) max = max->r;
	return max;
}
void BST::preorder_traversal(NODE& n) const
{
	std::cout<<n.key<<std::endl;
	if(n.l != 0) preorder_traversal(*n.l);
	if(n.r != 0) preorder_traversal(*n.r);
}
void BST::postorder_traversal(NODE& n) const
{
	if(n.l != 0) postorder_traversal(*n.l);
	if(n.r != 0) postorder_traversal(*n.r);
	std::cout<<n.key<<std::endl;
}
void inorder_traversal(NODE& n) const
{
	if(n.l != 0) postorder_traversal(*n.l);
	std::cout<<n.key<<std::endl;
	if(n.r != 0) postorder_traversal(*n.r);
}
void preorder_traversal(int k) const
{
	preorder_traversal(bst_search({k}));
}
void postorder_traversal(int k) const
{
	postorder_traversal(bst_search({k}));
}
void inorder_traversal(int k) const
{
	inorder_traversal(bst_search({k}));
}
