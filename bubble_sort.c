#include <stdio.h>
#include <stdlib.h>

/* 
 * 每次将最大的元素，像石子一样沉到最后。
 * 所以，最小的元素就像气泡一样上升到最前面。因此就bubble sort 
 */
int bubble_sort(int a[], int n)
{
	int i, j, flag = 1;
	int tmp;

	for (i = 1; i < n && flag == 1; i++) {
		flag = 0;
		for (j = 0; j < n-i; j++) {
			if (a[j] > a[j+1]) {
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
				flag = 1;
			}
		}
	}

	return 0;
}

int main()
{
	int a[8] = {28, 19, 48, 89, 2, 28, 878, 96};
	int i;

	bubble_sort(a, 8);
	for (i = 0; i < 8; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	
	return 0;
}
