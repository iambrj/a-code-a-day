int* counting_sort(int a[], int size, int n) // n = max element
{
	int i;
	//array to store sorted elements
	int* sorted = new int [size];
	//array to store number of occurrences of each element
	int count[n + 1];
	//array to store number of elements less than each element
	int less[n + 1];
	//initialize
	for(i = 0; i < n + 1; i ++) 
	{
		less[i] = 0;
		count[i]=0;
	}
	for(i = 0; i < size; i ++) 
	{
		//set count
		count[ a[i] ] ++;
	}
	for(i = 1; i < n + 1; i ++) 
	{
		//set less[i] using count and less[i - 1]
		less[i] = count[i - 1] + less[i - 1];
	}
	for(i = size - 1; i >= 0; i --) 
	{
		//set each element into its correct position
		sorted[ less[ a[i] ] ] = a[i];
		//update less
		less[ a[i] ] --;
	}
	return sorted;
}
