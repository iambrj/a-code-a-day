#include "bubblesort.h"

void swap(int* a, int* b)
{
	int temp = *a;
	*a  = *b;
	*b  = temp;
}

void bubblesort(int* a, int n)
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = i + 1; j < n; j++)
			if(a[j] < a[i]) swap(&a[i], &a[j]); //swap
	}
}
