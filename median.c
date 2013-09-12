#include <stdio.h>
#include <stdlib.h>

/*
 * partition a[p~r], both inclusive
 * a[r] is the pivat
 * return q, where a[p~q-1]<=a[q]<=a[q+1, r]
 */
int partition(int a[], int p, int r)
{
	int i, j;
	int pivat = a[r], tmp;
	i = p - 1;

	for (j = p; j < r; j++) {
		if (a[j] < pivat) {
			i++;
			/* swap a[i] and a[j] */
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}

	/* exchange a[i+1] and a[r] */
	tmp = a[i+1];
	a[i+1] = a[r];
	a[r] = tmp;

	return i+1;
}

int randomized_partition(int a[], int p, int r)
{
	int tmp, i;
	time_t t;

	srand(time(&t));
	i = p + rand()%(r-p+1);

	tmp = a[r];
	a[r] = a[i];
	a[i] = tmp;

	return partition(a, p, r);
}

/* 
 * find the ith element from array a[p .. r] (both inclusive)
 * the expected time of randomized_selet is O(n)
 */

int randomized_select(int a[], int p, int r, int i)
{
	int q, k;

	if (i > r-p+1) {
		fprintf(stderr, "check i\n");
		exit(-1);
	}
	if (p == r)
		return a[p];
	q = randomized_partition(a, p, r);
	
	k = q-p+1;
	if (k == i) 
		return a[q];
	else if (i < k)
		randomized_select(a, p, q-1, i);
	else 
		randomized_select(a, q+1, r, i-k);
}

int main()
{
	int a[5] = {3, 8, 2, 9, 4};
	int i;
	i = randomized_select(a, 0, 4, 3);
	printf("%d\n", i);

	return 0;
}
