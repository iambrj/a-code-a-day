#ifndef _STACK_H_
#define _STACK_H_
#include <cstdlib>
class stack
{
	private:
		int SIZE,MAX;
		int* HEAD;
	public:
		stack(int n = 0);
		bool empty() const {return SIZE == -1;}
		int size() const {return SIZE;}
		int& top() const {return HEAD[SIZE]0;}
		bool push(int);
		bool pop();
};
#endif
