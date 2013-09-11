/*
 * n个d位数，每位有k个可能的取值。 RADIX SORT 使用的稳定的方法O(n+k)，
 * 那么它的时间复杂度为O(d(n+k))
 */
#include <stdio.h>
#include <stdlib.h>

#define SHOWPASS

void print_array(int *a, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d\t", a[i]);
	printf("\n");
}

void radixsort(int *a, int n)
{
	int i, max,  exp = 1;
	int *tmp = (int *)malloc(n*sizeof(int));
	if (tmp == NULL) {
		fprintf(stderr, "malloc error\n");
		exit(-1);
	}
	
	/* find the maximum number of the array */
	max = a[0];
	for (i = 1; i < n; i++) {
		if (a[i] > max)
			max = a[i];
	}

	while (max / exp > 0) {
		/* counting sort on every digit */
		int bucket[10] = {0};

		for (i = 0; i < n; i++)
			bucket[a[i] / exp % 10]++;
		/* now b[i] contains the number of elements equal to i */

		for (i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		/* now b[i] contains the number of elements less than or equal to i */

		for (i = n - 1; i >= 0; i--)
			tmp[--bucket[a[i] / exp % 10]] = a[i];

		for (i = 0; i < n; i++)
			a[i] = tmp[i];

		exp *= 10;

#ifdef SHOWPASS
		printf("PASS   : ");
		print_array(a, n);
#endif
	}
	free(tmp);
}

int main()
{
	int a[5] = {14, 541, 8, 788, 3324};
	int i, n;
	n = 5;

	printf("orignal: ");
	print_array(a, n);

	radixsort(a, n);

	printf("\nSORTED : ");
	print_array(a, n);

	return 0;
}
