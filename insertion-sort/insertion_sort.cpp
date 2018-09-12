void insertion_sort(int a[], int n)
{
	int i, j, key;
	for(i = 1; i < n; i++) //i keeps track of the divide between sorted and unsoreted arrays
	{
		key = a[i]; //first element of currently unsorted array
		for(j = i - 1;j >= 0; j--)
		{
			if(key > a[j]) break; //break at the "correct" position
			a[j + 1] = a[j];
		}
		a[j+1] = key; //inserting at "correct position"
	}
}
