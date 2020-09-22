/*
*  Determines if n is a multiple of m.
*
*  @author 游子霆
*  @ID B07505051
*  @Department Engineering Science and Ocean Engineering
*@  Affiliation National Taiwan University
*/

#include <iostream>

using namespace std;

bool isMultiple(long n, long m)
{
	// Check if n can be divided by m with no remainder.
	if (n % m != 0)
	{
		return false;
	}

	return true;
}

/* int main()
{
	// Case: n is a multiple of m.
	int n1 = 20;
	int m1 = 4;

	cout << isMultiple(n1, m1) << "\n";

	// Case: n is not a multiple of m.
	int n2 = 21;
	int m2 = 2;

	cout << isMultiple(n2, m2) << "\n";

	return 0;
} */
