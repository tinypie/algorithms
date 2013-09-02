#include <stdio.h>
#include <stdlib.h>

/*
 * partition a[p~r], both inclusive
 * a[r] is the pivat
 * return q, where a[p~q-1]<=a[q]<=a[q+1, r]
 * P97(introduction to algorithm has the picture illustrate)
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

/*
 * a[p,r] both inclusive 
 */
int quick_sort(int a[], int p, int r)
{
	int q;
	if (p <= r) {
		q = partition(a, p, r);
		quick_sort(a, p, q-1);
		quick_sort(a, q+1, r);
	}
}
		
/*
 * iterative quick sort in one function
 * both inclusive
 * the pivat is the a[low]
 */
int quick_sort_ite(int a[], int low, int high)
{
	int i = low, j = high;
	int tmp;

	tmp = a[low];

	while (i < j) {
		while (i < j && a[j] > tmp)
			j--;
		if (i < j) {
			a[i] = a[j];
			i++;
		}

		while (i < j && a[i] <= tmp) 
			i++;
		if (i < j) {
			a[j] = a[i];
			j--;
		}
	}
	a[i] = tmp;

	if (low < i) 
		quick_sort_ite(a, low, i-1);
	if (i < high)
		quick_sort_ite(a, i+1, high);
	return 0;
}
	
		
int main()
{
	int a[5] = {3, 8, 2, 9, 4};
	int i;
	quick_sort(a, 0, 4);

	for (i = 0; i < 5; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
