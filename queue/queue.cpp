#include "queue.h"
queue::queue(int n)
{
	MAX = n;
	HEAD = 0;
	TAIL = 0;
	SIZE = 0;
	QUEUE = new int [n];
}
bool queue::push(int x)
{
	if(this->full()) return false;
	QUEUE[TAIL] = x;
	TAIL--;
	TAIL %= MAX;
	SIZE++;
	return true;
}
bool queue::pop()
{
	if(this->empty()) return false;
	HEAD--;
	HEAD %= MAX;
	SIZE--;
	return true;
}
