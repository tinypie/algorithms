/* 
 * divide-and-conquer approach
 *  (1)Divide the problem into a nummber of subproblems
 *  (2)Conquer the subprolbems by solving them recursively.
 *  (3)Combine the solutions to the subproblems into the solution 
 *     of the the original problem.
 * the O(n) = nlgn
 */
#include <stdio.h>
#include <stdlib.h>

/* from middle to high or [middle, high] both inclusive */
void merge(int *p, int low, int middle, int high)
{
	int start1, start2, k, i;
	int *tmp;

	start1 = low;
	start2 = middle + 1;
	tmp = (int *) malloc((high-low+1)*sizeof(int));
	if (tmp == NULL) {
		strerror("malloc error\n");
	}

	for (k = 0; start1 <= middle && start2 <= high; k++) {
		if (p[start1] < p[start2]) {
			tmp[k] = p[start1++];	
		} else {
			tmp[k] = p[start2++];
		}
	}

	while (start1 <= middle) {
		tmp[k++] = p[start1++];
	}

	while (start2 <= high) {
		tmp[k++] = p[start2++];
	}

	for(i = 0; i < high-low+1; i++) {
		p[low+i] = tmp[i];
	}
	free(tmp);
}
		
/* [low, high] inclusive */
void merge_sort(int *p, int low, int high)
{
	int middle;
	middle = (low + high) / 2;
	if (low < high) {
		merge_sort(p, low, middle);
		merge_sort(p, middle+1, high);
		merge(p, low, middle, high);
	}
}


/* test one example */
int main()
{
	int a[8] = {28, 19, 48, 89, 2, 28, 878, 96};
	int i;

	merge_sort(a, 0, 7);
	for (i = 0; i < 8; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	
	return 0;
}
