#include <iostream>
#include <cstdlib>
#include "bucketsort.h"
using namespace std;
int main()
{
	int n, i;
	std::cin >> n;
	double* a = new double [n];
	for(i = 0; i < n; i++) a[i] = (rand()%1001)/1001.0;
	std::cout<<"Before sorting:\n";
	for(i = 0; i < n; i++) cout<<a[i]<<' ';
	cout<<endl;
	double* b;
    b = bucketsort(a,n);
	std::cout<<"After sorting:\n";
	for(i = 0; i < n; i++) cout<<b[i]<<' ';
	cout<<endl;
}
