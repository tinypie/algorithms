/*
 * x^n (x to the pow of n) in O(lgn) time
 * use divide and conquer 
 *     |  x^(n/2) * x^(n/2) if n is ever
 * x = |
 *     |  x^((n-1)/2) * x^((n-1)/2) * x if n is odd
 *
 */

#include <stdio.h>

unsigned long my_pow(int x, int n) 
{
	if (n == 1) 
		return x;
	else if (n % 2 == 0)
		return my_pow(x, n/2) * my_pow(x, n/2);
	else 
		return (my_pow(x, n/2) * my_pow(x, n/2) * x);
}

unsigned long my_pow_ite(int x, int n)
{
	int ret = 1;
	int factor = x;
	
	while (n) {
		if (n & 1) 
			ret *= factor;

		factor *= factor;
		n /= 2;
	}

	return ret;
}



int main()
{
	printf("2^10 = %d\n", my_pow(2, 3));
	return 0;
}
