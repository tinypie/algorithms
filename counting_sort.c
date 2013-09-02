/*
 * counting sort in linear time.
 * Assumes that each of the n input element is an interger in the range
 * of 0 to k. The run time is O(k+n) with a space O(k+n)
 * 适合数据都属于一个小区间的整数
 * 是稳定的，当k=O(n)时，一般会采用计数排序，这时的运行时间为O(n).
 * 通过用于，基数排序的一个子过程。
 */
#include <stdio.h>
#include <stdlib.h>

void counting_sort(int array[], const int n, int k)
{
	int count[k];	// provides tempory working storage
	int tmp[n];	// holds the sorted oupput
	int i, j;

	/* initialize the count array */
	for (i = 0; i < k; i++)
		count[i] = 0;
	
	for (i = 0; i < n; i++) {
		count[array[i]]++;
	}
	for (i = 1; i < k; i++) {
		count[i] += count[i-1];
	}

	for (i = n - 1; i >=0; i--) {
		j = --count[array[i]];
		tmp[j] = array[i];
	}
	
	for (i = 0; i < n; i++)
		array[i] = tmp[i];
	
}

int main()
{
	int i;
	int array[5] = {9, 5, 7, 8, 2};

	counting_sort(array, 5, 10);

	for (i = 0; i < 5; i++)
		printf("%d ", array[i]);
	putchar('\n');
	return 0;
}
