/* p-->index of first element r-->index of last element*/
#include "mergesort.h"

void merge(int* a, int p, int q, int r) // auxillary merge procedure
{
	int n1, n2;
	n1 = q - p + 1; // n1 is the length of left subarray
	n2 = r - q; // n2 is the length of right subarray
	int i, j, k;
	int* left = new int [n1]; // allocate memory for left subarray
	int* right = new int [n2]; // allocate memory for right subarray
	for(i = 0; i < n1; i++) left[i] = a[p+i]; // initialize left subarray
	for(j = 0; j < n2; j++) right[j] = a[q+1+j]; //iniatilize right subarray
	// i keeps track of left's index
	// j keeps track of right's index
	// k keeps track of a's index
	for(i = 0, j = 0, k = p; i < n1 && j < n2 && k < n1 + n2; k++)
	{
		// update a[k] with the lesser of left[i] and right[j]
		if(left[i] < right[j])
		{
			a[k] = left[i];
			i++;
		}
		else
		{
			a[k] = right[j];
			j++;
		}
	}
	// if remaining, update remaining a[k] with remaining left[i] 
	for(; i < n1 && k < n1 + n2; i++, k++)
	{
		a[k] = left[i];
	}
	// if remaining, update remaining a[k] with remaining right[j]
	for(;j < n2 && k < n1 + n2; j++, k++)
	{
		a[k] = right[j];
	}
}

void merge_sort(int* a, int p, int r)
{
	if(p < r) // to make sure that it is not the base case {
		int q = (p + r) / 2; // mid point
		merge_sort(a, p, q); // recursively sort left subarray
		merge_sort(a, q + 1, r); // recursively sort right subarray
		merge(a, p, q, r); // merge the sorted subarrays
	}
}
