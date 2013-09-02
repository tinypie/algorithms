/*
 * binary search use divide and conquce strategy
 * so here is the recurrenc implement
 */
#include <stdio.h>
#include <stdlib.h>

/* here [low, high] inclusive */
int binary_search(int a[], int low, int high, int key)
{
	int mid = (low + high) / 2;

	if (low < high) {
		if (a[mid] == key) 
			return mid;
		else if (a[mid] > key)
			binary_search(a, low, mid-1, key);
		else 
			binary_search(a, mid+1, high, key);
	} else if (low == high) {
		if (a[mid] == key)
			return mid;
		else 
			return -1;
	} else 
		return -1;
		
}


/* 
 * here is the iterative method
 */

int binary_search_iter(int a[], int n, int key)
{
	int low = 0;
	int high = n-1;
	int mid;

	while (low <= high) {
		mid = (low + high) / 2;
		if (a[mid] == key) {
			return mid;
		} else if (a[mid] > key) {
			high = mid -1;
		} else {
			low = mid + 1;
		}
	}

	return -1;
}

int main()
{
	int a[8] = {23, 25, 37, 73, 97, 199, 899, 1000};
	int ret = binary_search(a, 0, 7,  199);
	

	printf("73, is in a[%d]\n", ret);

	return 0;
}


	
