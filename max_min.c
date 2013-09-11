#include <stdio.h>
#include <stdlib.h>

/* 同时，找到最大的和最小的
 * 思想是成对成对的比较，这样需要的比较次数是至多为1.5n
 */

int max_min(int a[], int n, int *max, int *min)
{
	int i;

	if (n == 1) {
		*max=*min=a[0];
		return 0;
	}

	if (a[0] > a[1]) {
		*max = a[0];
		*min = a[1];
	} else {
		*max = a[1];
		*min = a[0];
	}

	for(i = 2; i < n; i += 2) {
		if (i + 1 == n) {
			if (a[i] > *max) {
				*max = a[i];
			}
			if (a[i] < *min) {
				*min = a[i];
			}
		} else {
			if (a[i] > a[i+1]) {
				if (a[i] > *max) {
					*max = a[i];
				}
				if (a[i+1] < *min) {
					*min = a[i+1];
				}
			} else {
				if (a[i+1] > *max) {
					*max = a[i+1];
				} 
				if (a[i] < *min) {
					*min = a[i];
				}
			}
		}
	}

	return 0;
}

int main()
{
	int a[6] = {3, 4, 51, 561, 85, 0};

	int max, min;

	max_min(a, 2, &max, &min);
	printf("%d\t%d\n", max, min);
	return 0;
}
