#include "heap_sort.h"
#include <iostream>
using namespace std;
int main()
{
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	build_max_heap(a,10);
	for(int i = 0; i < 10; i++) cout<<a[i]<<endl;
	cout<<a[left_child(0)]<<endl;
	cout<<a[right_child(0)]<<endl;
}
