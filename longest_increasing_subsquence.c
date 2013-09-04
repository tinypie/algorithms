/*
 * longest increasing subsequence
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * dynamic programming
 *
 * optimal substructure
 * LIS[i] = max{1, LIS[k]+1},  k < i && arr[i] > arr[k]
 * 
 * time: O(n^2)
 *
 */
int dp[100];
int len;


int lis_dp(int a[], int n)
{
	int i, j, max = 1;
#if 0
	int *dp = malloc(n*sizeof(int));
	if (dp == NULL) 
		exit(-1);
	memset(dp, 0, n*sizeof(int));
#endif

	for(i = 0; i < n; i++) {
		dp[i] = 1;
		for (j = 0; j < i; j++) {
			if (a[i] > a[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				if (dp[i] > max)
					max = dp[i];
			}
		}
	}
	len = max;

	return max;
}

void output(int a[], int n)
{
	int flag = 0;

	if (n < 0 || len == 0)
		return;
	if (dp[n] == len) {
		len--;
		 flag = 1;
	}
	output(a, n-1);

	if (flag == 1) {
		printf("%d\t", a[n]);
	}
}


/* maxv[left] 是第一个大于 data的 */
int binary_search(int *maxv, int len, int data)
{
	int low, high, mid;

	low = 0; 
	high = len-1;

	while (low <= high) {
		mid = (low + high) / 2;
		if (maxv[mid] < data) { 
			low = mid + 1;
		} else {
			high = mid - 1;
		}

	}

	return low;
}

/* 
 * time complexity : O(nlgn)
 *
 * perfect
 *
 * maxV[i] ==>  长度为i的所有递增子序列里面，最大元素中的最小值。
 */

int lis_perfect(int a[], int n) 
{
	int i, len, pos;
	int *maxv = (int *) malloc(n*sizeof(int));

	maxv[0] = a[0];
	len = 1;

	for (i = 1; i < n; i++) {
		if (a[i] > maxv[len-1]) {
			maxv[len++] = a[i];
		} else {
			pos = binary_search(maxv, len, a[i]);
			maxv[pos] = a[i];
		}
	}

	free(maxv);
	return len;
}

			
	


int main() 
{
	int a[8] = {1,-1,2,-3,4,-5,6,-7};

	printf("%d\n", lis_dp(a,8));

	output(a, 8);

	printf("\n%d\n", lis_perfect(a,8));

	return 0;
}

