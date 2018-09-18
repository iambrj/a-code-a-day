#include "heap_sort.h"
void max_heapify(int* a, int heap_size, int i) //fixes max heap at subtree with root i
{
	int l, r;
	l = left_child(i);
	r = right_child(i);
	int largest = i; //finding the largest among i, its left and right children 
	if(l < heap_size && a[l] > a[i]) largest = l;
	if(r < heap_size && a[r] > a[largest]) largest = r;
	if(largest != i) //so that an element cannot be swapped by itself and cause infinite recursion
	{
		swap(&a[i], &a[largest]);
		//recursively fix heap property at swapped element
		max_heapify(a, heap_size, largest);
		//TODO make an interative version of max_heapify
	}
}

void build_max_heap(int* a, int size) //builds a max heap using elements of array
{
	int i;
	//go to every non-leaf element and run max_heapify on it
	for(i = (size - 1) / 2; i > -1; i--)
		max_heapify(a, size, i);
}

void heap_sort(int* a, int size)
{
	int i, heap_size = size;
	build_max_heap(a, size);
	for(i = size - 1; i > 0; i--)
	{
		//swap the root (max) with the last element
		swap(&a[0], &a[i]);
		heap_size--;
		//fix violations
		max_heapify(a, heap_size, 0);
	}
}

void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
