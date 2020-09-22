/*
*  Makes the dot prodict of two arrays of integers, a[] and b[].
*  @author 游子霆
*  @ID B07505051
*  @Department Engineering Science and Ocean Engineering
*  @Affiliation National Taiwan University
*/

#include <iostream>

using namespace std;

int dotProduct(int a[], int b[], int n)
{
	int *c = new int[n]; // Initialize an array of integers with size n.

	int sum = 0;

	// Multiply a[i] with b[i] and save each outcome to c
	for (int i = 0; i < n; i++)
	{
		c[i] = a[i] * b[i];
	}

	// Sum up items in c
	for (int i = 0; i < n; i++)
	{ //add all c together to make it the dot product
		sum += c[i];
	}

	// Return the result
	return sum;
}

/* int main(){
	const int n = 10;

	int a[n] = {-1, 0, 2, 15, 7, 6, -4, 8, 21, -13};
	int b[n] = {5, 9, -18, 16, 0, 1, -4, 18, -2, 12};

	dotProduct(a, b, n);

	cout << dotProduct(a, b, 10)<<"\n";

	return 0;
} */
