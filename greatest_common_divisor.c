#include <stdio.h>
#include <stdlib.h>

/* 
 * one solution is 辗转相除法
 * f(x,y)=f(y, x%y) (x >= y >0)
 *
 * another solution is 
 * f(x,y)=f(x-y, y) (x>=y>0)
 */
int gcd_zhan_ite(int x, int y)
{
	int tmp;
	if (x == 0) 
		return y;
	if (y == 0)
		return x;

	if (x < y) {
		tmp = x;
		x = y;
		y = tmp;
	}

	while (y != 0) {
		tmp = y;
		y = x % y;
		x = tmp;
	}
	return x;
}

int gcd_zhan(int x, int y)
{
	return (!y)? x : gcd_zhan_ite(y, x%y);
}


/* 
 * this is the very good solution but have one pitfall
 * when x and y vaied widely , such as x = 10000000000, y = 1
 * then the iteration times is very large
 *
 */
int gcd_jian_ite(int x, int y)
{
	while (x != y) {
		if (x > y)
			x -= y;
		else 
			y -= x;
	}

	return x;
}

int gcd_jian(int x, int y)
{
	if (x < y)
		return gcd_jian(y, x);
	if (y == 0)
		return x;
	else 
		return gcd_jian(x-y, y);
}

/*
 * fix the pitfall when x and y vaied widely.
 * if x and y both are even, then gcd(x, y) = 2*gcd(x>>1, y>>1)
 * if x is even while y is odd, then gcd(x,y) = gcd(x>>1, y)
 * if x is odd while y is even, then gcd(x,y) = gcd(x, y>>1)
 * if x and y both are odd, then gcd(x,y) = gcd(y, x-y) (x >y)
 */
int gcd_jian_fix(int x, int y)
{
	if (x < y)
		return gcd_jian_fix(y, x);

	if (y == 0)
		return x;
	
	else {
		if (x % 2 == 0) {
			if (y % 2 == 0) 
				 return (gcd_jian_fix(x>>1, y>>1) << 1);
			else 
				 return gcd_jian_fix(x>>1, y);
		} else {
			if (y % 2 == 0)
				 return gcd_jian_fix(x, y>>1);
			else
				 return gcd_jian_fix(y, x-y);
		}
	}

}

int main()
{
	printf("%d\n", gcd_jian(12, 15));
	
	return 0;
}
		

