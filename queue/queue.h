#ifndef _QUEUE_
#define _QUEUE_
class queue
{
	private:
		int HEAD,TAIL,MAX,SIZE;
		int* QUEUE;
	public:
		queue(int n);
		bool empty() const {return SIZE == 0;}
		bool full() const {return SIZE == MAX}
		int& front() const {return QUEUE[HEAD];}
		int& back()const {return QUEUE[TAIL];}
		int	size() const {return SIZE;}
		bool push(int);
		bool pop();
};
#endif
