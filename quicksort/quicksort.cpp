/*low-->index of first element high-->index of last element*/
#include <cstdlib> // for rand()

void swap(int* a, int* b) //swap values pointed by a and b
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int a[], int low, int high) //partition using last element as the pivot
{
	int q, u; // q keeps track of pivot's final position
	int& pivot = a[high];
	//move all elements less than pivot before pivot
	//and keep track of pivot's final position in q
	for(q = low, u = low++; u < high; u++)
	{
		if(a[u] < pivot)
		{
			swap(&a[u], &a[q]);
			q++;
		}
	}
	swap(&a[high], &a[q]); //swapping pivot into its final position
	return q;
}

int quickSort(int a[], int low, int high)
{
	if(low < high) // check for base case
	{
		int p = partition(a, low, high); // partition using last element as pivot
		quickSort(a, low, p - 1); // recursively sort left subarray
		quickSort(a, p + 1, high); // recursively sort right subarray
	}
}

int randomised_quickSort(int* a, int low, int high)
{
	if(low < high) // check for base case
	{
		int r = rand() % (high - low + 1); // pick a random number between 0 and size-1
		swap(&a[high],&a[r]); //swap it with last element
		int p = partition(a,low,high);
		randomised_quickSort(a,low,p-1);
		randomised_quickSort(a,p+1,high);
	}
}
