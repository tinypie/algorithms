/* heap sort */

#include <stdio.h>
#include <stdlib.h>

int max_heap_ite(int a[], int n, int i)
{
	int k, j, flag;
	int tmp;

	k = i;
	j = 2 * i + 1;

	tmp = a[i]; 
	flag = 0;

	while(j < n && flag == 0) {
		if (j < n -1 && a[j] < a[j+1])
			j++;
		if (tmp > a[j])
			flag = 1;
		else {
			a[k] = a[j];
			k = j;
			j = 2*k+1;
		}
	}
	a[k] = tmp;
	return 0;
}
/*
 * 自底向上建堆、自上向下调整
 * n is exclusive which mean a[n] is not exist. n is the lenght 
 * of the array
 */
int max_heap(int a[], int n, int i)
{
	int left, right, largest;
	int tmp;

	left = 2*i + 1;
	right = left + 1;

	if (right < n) {
		largest = (a[left] > a[right]) ? left : right;
	} else if (left < n)
		largest = left;
	else
		return 0;
	
	if (a[i] > a[largest])
		largest = i;
	
	if (i != largest) {
		tmp = a[i];
		a[i] = a[largest];
		a[largest] = tmp;
		max_heap(a, n, largest);
	}
	return 0;
}

int build_max_heap(int a[], int n)
{
	int i;
	//for (i = (n-1)/2; i >= 0; i--) {
	for (i = n/2-1; i >= 0; i--) {
		max_heap(a, n, i);
	}

	return 0;
}

int heap_sort(int a[], int n)
{
	int i, tmp;

	build_max_heap(a, n);

	for (i = n-1; i > 0; i--) {
		tmp = a[i];
		a[i] = a[0];
		a[0] = tmp;
		max_heap(a, i, 0);
	}

	return 0;
}

int main()
{
	int a[5] = {3, 8, 2, 9, 4};
	int i;
	heap_sort(a, 5);

	for (i = 0; i < 5; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
