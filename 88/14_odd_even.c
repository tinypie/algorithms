#include <stdio.h>
#include <stdlib.h>

// 奇数在偶数的前面
//

int odd_even(int *a, int len)
{
	int *start, *end, tmp;
	if (a == NULL || len <= 0) 
		return -1;
	
	start = a;
	end = a + len - 1;

	while (start < end) {
		while (start < end && (*start & 0x1) == 1)
			start++;

		while (end > start && (*end & 0x1) == 0)
			end--;

		if (start < end) {
			tmp = *start;
			*start = *end;
			*end = tmp;
		}
	}
	
	return 0;
}

int main()
{
	int a[4] = {3, 4, 6, 7};
	int i;

	odd_even(a, 4);

	for (i = 0; i < 4; i++) 
		printf("%d\t", a[i]);
	
	return 0;
}
