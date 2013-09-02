#include <stdio.h>
#include <stdlib.h>

/*
 * 每次从待排序的数据元素集合中，选取关键字最小（最大）的元素放到数据元素集合的最前（最后）
 * O(n^2) best and good. not stable
 */

int select_sort(int a[], int n)
{
	int i, j, small, flag = 1;
	int tmp;

	for (i = 0; i < n-1 && flag == 1; i++) {
		flag = 0;
		small = i;
		for (j = i+1; j < n; j++) {
			if (a[small] < a[j]) {
				small = j;
			}
		}

		if (small != i) {
			flag = 1;
			tmp = a[i];
			a[i] = a[small];
			a[small] = tmp;
		}
	}
	return 0;
}


int main()
{
	int a[5] = {3, 8, 2, 9, 4};
	int i;
	select_sort(a, 5);

	for (i = 0; i < 5; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
			
