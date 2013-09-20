#include <stdio.h>
#include <stdlib.h>

/*
 * 暴力求解的时间复杂度是O(n^3), 优化后为O(n^2)
 *
 * There are two solution to this problem.
 * One is use divide-and-conquic stratege which time is O(nlgn) (Introduction to algorithm p 41)
 * Another is linear time solution.	(programming pearls p77)
 */

/* 
 * divide and conquic
 */

int find_cross_sub(int *a, int low, int mid, int high, int *start, int *end)
{
	int left_sum, right_sum, sum;
	int i;
	sum = 0;	
	left_sum = a[mid];
	*start = mid;
	for (i = mid; i >= low; i--) {
		sum += a[i];
		if (sum > left_sum) {
			left_sum = sum;
			*start = i;
		}
	}

	sum = 0;
	right_sum = a[mid+1];
	*end = mid+1;
	for (i = mid+1; i <= high; i++) {
		sum += a[i];
		if (sum > right_sum) {
			right_sum = sum;
			*end = i;
		}
	}

	return left_sum+right_sum;
}

int find_max_sub(int *a, int low, int high, int *start, int *end)
{
	int mid, left_low, left_high, right_low, right_high, cross_low, cross_high;
	int left_sum, right_sum, cross_sum;

	if (low == high) {
		*start = low;
		*end = high;
		return a[low];
	} else {
		mid = (low+high)/2;
		left_sum = find_max_sub(a, low, mid, &left_low, &left_high);
		right_sum = find_max_sub(a, mid+1, high, &right_low, &right_high);
		cross_sum = find_cross_sub(a, low, mid, high, &cross_low, &cross_high);
		if (left_sum >= right_sum && left_sum >= cross_sum) {
			*start = left_low;
			*end = left_high;
			return left_sum;
		} else if (right_sum >= left_sum && right_sum >= cross_sum) {
			*start = right_low;
			*end =right_high;
			return right_sum;
		} else {
			*start = cross_low;
			*end = cross_high;
			return cross_sum;
		}
	}
}
		
/*
 * 不能求元素都是负值的情况，如果元素都是负值，返回的结果是0
 * 如果处理都为负值的情况的，只需要找到其中，最大的元素，判断与max_so_far 的大小。
 */
int scanning(int *a, int n)
{
	int i, max_so_far, max_ending_here;

	max_so_far = max_ending_here = 0;

	for (i = 0; i < n; i++) {
		max_ending_here = (max_ending_here + a[i] > 0) ? (max_ending_here + a[i]) : 0;
		max_so_far = max_so_far > max_ending_here ? max_so_far : max_ending_here;
	}

	return max_so_far;
}

/*
 * dynamic programming 
 *
 * start[i] = max{A[i], start[i+1]+A[i]} 表示包含A[i]的和最大的数组和
 * All[i] = max{start[i], All[i+1]} 表示A[i]~A[n-1]中，最大的数组和
 *
 */
int max(int x, int y)
{
	return (x>y) ? x : y;
}

int maximum_dp(int a[], int n)
{
	int all, start, i;

	all = start = a[n-1];

	for (i = n-2; i >= 0; i--) {
		start = a[i] > (start + a[i]) ? a[i] : (start + a[i]);
		all = start > all ? start : all;
	}

	return all;
}

int main()
{
	int start, end, a[10] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};
	int b[4]= {-4, -3, -2, -7};
	int sum;

//	sum = find_max_sub(b, 0, 3, &start, &end);
//	printf("from %d to %d ==> %d\n", start, end, sum);
	sum = scanning(a, 10);
	printf("%d\n", sum);
	printf("%d\n", maximum_dp(b, 4));
	return 0;
}
