#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

bool witness(unsigned long long a, unsigned long long n)
{
	unsigned long long u = n - 1, t = 0;
	while(u % 2 == 0)
	{
		u /= 2;
		t += 1;
	}
	unsigned long long x1, x2;
	x1 = (unsigned long long)(pow(a, u)) % n;
	for(unsigned long long i = 0; i < t; i++)
	{
		x2 = (x1 * x1) % n;
		if(x2 == 1 && x1 != 1 && x1 != n - 1)
			return true;
		x1 = x2;
	}
	if(x2 != 1)
		return true;
	return false;
}

bool miller_rabin(unsigned long long p, unsigned long long iterations) // true if p prime
{
	for(int i = 0; i < iterations; i++)
	{
		if(witness(rand() % p, p))
			return false;
	}
	return true;
}

int main()
{
	unsigned long long p;
	cout << "Enter a number: ";
	cin >> p;
	if(miller_rabin(p, 10))
		cout << p << " is a prime" << endl;
	else
		cout << p << " is not a prime" << endl;
}
