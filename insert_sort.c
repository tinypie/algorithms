#include <stdio.h>
#include <stdlib.h>

int insert_sort(int a[], int n)
{	
	int i, j;
	int tmp;

	for (i = 1; i < n; i++) {
		tmp = a[i];
		j = i - 1;
		while (j > -1 && tmp < a[j]) {
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = tmp;
	}

	return 0;
}

int main()
{
	int a[5] = {3, 8, 2, 9, 4};
	int i;
	insert_sort(a, 5);

	for (i = 0; i < 5; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
