#include "bucketsort.h"
double* bucketsort(double* a, int size)
{
	int i, j, k = 0;
	std::vector<double> sublist[size];
	for(i = 0; i < size; i++) 
	{
		k = size * a[i];
		sublist[k].push_back(a[i]);
	}
	for(i = 0; i < size; i++) sort(sublist[i].begin(), sublist[i].end());
	double* sorted = new double [size];
	k = 0;
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < sublist[i].size(); j++, k++) sorted[k] = sublist[i][j];
	}
	return sorted;
}
