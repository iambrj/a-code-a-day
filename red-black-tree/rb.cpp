#include "rb.h"
NODE NULL_NODE = {-1,0,0,0,0}; //sentinal
RBT::RBT()
{
	ROOT = 0; //initally points to nothing
}
NODE* RBT::search(int k) const // return pointer to node with key k
{
	if(ROOT == 0) return &NULL_NODE; //no tree
	NODE* CURRENT = ROOT;
	for(;;)
	{
		if(k == CURRENT->key) return CURRENT;
		else if(k < CURRENT->key)
		{
			if(CURRENT->l == 0) return &NULL_NODE; //no node with given key
			else CURRENT = CURRENT->l;
		}
		else if(k > CURRENT->key)
		{
			if(CURRENT->r == 0) return &NULL_NODE; //no node with given key
			else CURRENT = CURRENT->r;
		}
	}
}
NODE* RBT::minimum(NODE& n) const // return pointer to minimum node in subtree rooted at n
{
	if(ROOT == 0) return &NULL_NODE; //no tree
	NODE* current = search(n.key); //pointer to sub-tree root
	while(current->l != 0) current = current->l; //find minimun
	return current;
}
bool RBT::insert_node(int k) //returns true if successful, false otherwise.
{
	NODE* insert = new NODE;
	insert->key = k;
	insert->color = 1;
	NODE* curr = ROOT;
	if(ROOT == 0)
	{
		insert->color = 0;
		ROOT = insert;
		return true;
	}
	for(;;)
	{
		if(insert->key < curr->key)
		{
			if(curr->l == 0)
			{
				curr->l = insert;
				insert->p = curr;
				curr = curr->l; //to fix violations
				break;
			}
			else curr = curr->l;
		}
		else
		{
			if(curr->r == 0)
			{
				curr->r = insert;
				insert->p = curr;
				curr = curr->r; //to fix violations
				break;
			}
			else curr = curr->r;
		}
	}
	//fix violations
	while(curr->p->color == 1)
	{
		if(curr->p == curr->p->p->l)
		{
			NODE* aunt = curr->p->p->r;
			//case 1
			if(aunt->color == 1)
			{
				aunt->color = 0;
				curr->p->color = 0;
				curr->p->p->color = 1;
				curr = curr->p->p;
				if(curr == ROOT) 
				{
					ROOT->color = 0;
					return true;
				}
			}
			else if(curr == curr->p->r)
			{
				//case 2
				left_rotate(curr->p->key);
				curr = curr->l;
			}
			else
			{
				//case 3
				curr->p->color = 0;
				curr->p->p->color = 1;
				right_rotate(curr->p->p->key);
				ROOT->color = 0;
				return true;
			}
		}
		else
		{
			NODE* aunt = curr->p->p->l;
			//case 1
			if(aunt->color == 1)
			{
				aunt->color = 0;
				curr->p->color = 0;
				curr->p->p->color = 1;
				curr = curr->p->p;
				if(curr == ROOT) 
				{
					ROOT->color = 0;
					return true;
				}
			}
			else if(curr == curr->p->l)
			{
				//case 2
				right_rotate(curr->p->key);
				curr = curr->r;
			}
			//case 3
			else
			{
				curr->p->color = 0;
				curr->p->p->color = 1;
				left_rotate(curr->p->p->key);
				ROOT->color = 0;
				return true;
			}
		}
	}
	return false;
}
void RBT::transplant(NODE* u, NODE* v)
{
	if(u->p == 0) ROOT = v; // u is the root
	else if(u == u->p->l) u->p->l = v; // u is a left child
	else u->p->r = v; // u is a right child
	v->p = u->p;
}
bool RBT::delete_node(int k) //true if successful, false otherwise.
{
	NODE* z = search(k);
	NODE* y = z;
	NODE* x;
	int ocolor = y->color;
	if(z->l == 0 && z->r == 0)
	{
		if(z->p->l == z)
		{
			z->p->l = 0;
		}
		else
		{
			z->p->r = 0;
		}
	}
	else if(z->l == 0)
	{
		x = z->r;
		transplant(z, z->r);
	}
	else if(z->r == 0)
	{
		x = z->l;
		transplant(z, z->l);
	}
	else
	{
		y = minimum(*z);
		ocolor = y->color;
		x = y->r;
		if(y->p == z)
		{
			x->p = y;
		}
		else
		{
			transplant(y, y->r);
			y->r = z->r;
			y->r->p = y;
		}
		transplant(z, y);
		y->l = z->l;
		y->l->p = y;
		y->color = z->color;
	}
	//fix up violations
	if(ocolor == 0)
	{
		while(x != ROOT && x->color == 0)
		{
			if(x == x->p->l)
			{
				NODE* w = x->p->r;
				if(w->color == 1)
				{
					w->color = 0;
					x->p->color = 1;
					left_rotate(x->p->key);
				}
				if(w->l->color == 0 && w->r->color == 0)
				{
					w->color = 1;
					x = x->p;
				}
				else if(w->r->color == 0)
				{
					w->l->color = 0;
					w->color = 1;
					right_rotate(w->key);
					w = x->p->r;
				}
				if(w->color == 0 && w->r->color == 1)
				{
					w->color = x->p->color;
					x->p->color = 0;
					w->r->color = 0;
					left_rotate(x->p->key);
					x = ROOT;
				}
			}
			else
			{
				NODE* w = x->p->l;
				if(w->color == 1)
				{
					w->color = 0;
					x->p->color = 1;
					right_rotate(x->p->key);
				}
				if(w->r->color == 0 && w->l->color == 0)
				{
					w->color = 1;
					x = x->p;
				}
				else if(w->l->color == 0)
				{
					w->r->color = 0;
					w->color = 1;
					left_rotate(w->key);
					w = x->p->l;
				}
				if(w->color == 0 && w->l->color == 1)
				{
					w->color = x->p->color;
					x->p->color = 0;
					w->l->color = 0;
					right_rotate(x->p->key);
					x = ROOT;
				}
			}
		}
	}
}
void RBT::left_rotate(int k)
{
	NODE* x = search({k}); //node to be rotated
	NODE* y = x->r; //set y
	x->r = y->l; //y's left subtree is x's right subtree
	if(y->l != 0) y->l->p = x;
	y->p = x->p; //linking parent
	if(x->p == 0) ROOT = y;
	else if(x == x->p->l) x->p->l =y;
	else x->p->r = y;
	y->l = x; //put x on y's left
	x->p = y;
}
// same with x and y interchanged
void RBT::right_rotate(int k)
{
	NODE* x = search({k}); //node to be rotated
	NODE* y = x->l; //set y
	x->l = y->r; //y's right subtree is x's left subtree
	if(y->r != 0) y->r->p = x;
	y->p = x->p; //linking parent
	if(x->p == 0) ROOT = y;
	else if(x == x->p->r) x->p->r =y;
	else x->p->l = y;
	y->r = x; //put x on y's right
	x->p = y;
}
