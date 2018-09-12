#ifndef _HEAP_SORT_
#define _HEAP_SORT_
inline int left_child(int i) {return 2*i+1;} //returns left child
inline int right_child(int i) {return 2*i+2;} //returns right child
inline int parent(int i) {return (i-1)/2;} //returns parent
void max_heapify(int* array,int heap_size,int i); //fixes hax heap at subtree with root i
void build_max_heap(int* array,int size); //builds a max heap using elements of array
void swap(int* a,int* b); //swaps values pointed by the pointers
void heap_sort(int* array,int size); //the heapsort algorithm
#endif
