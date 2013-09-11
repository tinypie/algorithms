/*
 * there are three algorithms
 * O(2^n) --- 递归算法
 * O(n)   --- 迭代法
 * O(lgn) --- 矩阵法
 */

#include <stdio.h>
#include <stdlib.h>

/* recursion */
long fib_rec(int n) 
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else 
		return fib_rec(n-1) + fib_rec(n-2);
	
}


/* iteration */
long fib_ite(int n)
{
	long fn1, fn2, ret;
	int i;

	if (n <= 0) 
		return 0;
	else if (n == 1)
		return 1;
	
	fn1 = 0;
	fn2 = 1;
	for (i = 2; i <= n; i++) {
		ret = fn1 + fn2;
		fn1 = fn2;
		fn2 = ret;
	}

	return ret;
}

/* 
 * tpye of matrix 
 * 	| a, b |
 * 	| c, d |
 */
struct matrix {
	int a, b;
	int c, d;
};

struct matrix matrix_multiply(struct matrix p, struct matrix q)
{
	struct matrix r;

	r.a = p.a * q.a + p.b *q.c;
	r.b = p.a * q.b + p.b *q.d;

	r.c = p.c * q.a + p.d * q.c;
	r.d = p.c * q.b + p.d * q.d;

	return r;
}

/*
 * divide and conquer
 */
struct matrix matrix_pow(struct matrix m, int n)
{
	struct matrix tmp;

	if (n == 1) 
		return m;
	else if (n % 2 == 1) {
		return matrix_multiply(m, matrix_pow(m, n-1));
	} else {
		tmp = matrix_pow(m, n/2);
		return matrix_multiply(tmp, tmp);
	}
}

long fib_matrix(int n)
{
	struct matrix r,  m = { 1, 1, 1, 0};

	if (n == 0)
		return 0;
	if (n == 1) 
		return 1;
		
	r = matrix_pow(m, n-1);

	return r.a;
}
	
	
int main()
{
	printf("%d\n", fib_ite(8));
	printf("%d\n", fib_matrix(8));

	return 0;
}
	

