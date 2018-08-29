#include "stack.h"
stack::stack(int n)
{
	MAX = n;
	HEAD = new int [MAX];
	SIZE = -1;
}
bool stack::push(int x)
{
	if(SIZE == MAX) return false;
	HEAD[SIZE++] = x;
	return true;
}
bool stack::pop()
{
	if(this->empty()) return false;
	SIZE--;
	return true;
}
