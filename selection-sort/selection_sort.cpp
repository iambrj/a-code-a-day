void selection_sort(int a[], int n)
{
	int position = 0; //position keeps track of currently sorted subarray
	for(position = 0; position < n; position++)
	{
		swap(minimum(a, position, n), &a[pos]); //swap minimum from unsorted subarray with last element of sorted subarray
	}
}
void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int* minimum(int a[], int left, int right)
{
	int small = a[left], i, j = left;
	for(i = left; i < right; i++)
	{
		if(small > a[i]) 
		{
			small = a[i];
			j = i;
		}
	}
	return &a[j];
}
