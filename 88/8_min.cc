#include <iostream>
using namespace std;

int find(int *a, int start, int end)
{
	int result = a[start];
	for (int i = start+1; i <= end; i++) {
		if (result > a[i]) {
			result = a[i];
		}

	}
	return result;
}

// 旋转数组的最小值
int min(int *a, int len)
{
	int start, end, mid;
	if (a == NULL || len <= 0) 
		return -1;
	start = 0;
	end = len - 1;
	mid = start;

	while (a[start] >= a[end]) {
		if (end - start == 1) {
			mid = end;
			break;
		}

		mid = (start + end) / 2;

#if 1 // 1, 1, 1, 0, 1,1 (like this)
		// mid, start, end 三者相等
		if (a[mid] == a[start] && a[sart] == a[end]) 
			return find(a, start, end);

		if (a[mid] >= a[start]) {
			start = mid;
		} else
			end = mid;
	}
	return a[mid];
}
