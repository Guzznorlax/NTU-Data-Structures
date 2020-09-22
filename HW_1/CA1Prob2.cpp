/*
*  Finds the nearest prime numbers smaller and larger than the input number.
*
*  @author 游子霆
*  @ID B07505051
*  @Department Engineering Science and Ocean Engineering
*  @Affiliation National Taiwan University
*/

#include <iostream>
#include <math.h>

using namespace std;

int *showPrime(int p)
{
	int *result = new int[2];
	bool isPrime = true;

	// Check if p is prime
	for (int i = 2; i < p; i++)
	{
		if (p % i == 0)
		{
			isPrime = false;
			break;
		}
	}

	if (isPrime)
	{
		result[0] = p;
	}
	else
	{
		int ps, pl;

		// Finds the nearest prime number smaller than p.
		for (int n = p - 1; n >= 2; n--)
		{
			bool isPrime = true;

			// Check if n is prime
			for (int i = 2; i < n; i++)
			{
				if (n % i == 0)
				{
					isPrime = false;
					break;
				}
			}

			if (isPrime)
			{
				ps = n;
				break;
			}
		}

		// Finds the nearest prime number larger than p.
		for (int m = p + 1; m >= 2; m++)
		{
			bool isPrime = true;

			// Check if m is prime
			for (int i = 2; i < m; i++)
			{
				if (m % i == 0)
				{
					isPrime = false;
					break;
				}
			}

			if (isPrime)
			{
				pl = m;
				break;
			}
		}

		result[0] = ps;
		result[1] = pl;
	}

	return result;
}

/* int main()
{
	int *p = showPrime(104395302);
	cout << p[0] << "," << p[1];

	return 0;
} */
