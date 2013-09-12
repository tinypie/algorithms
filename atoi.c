/* to implement the atoi() */

#include <stdio.h>
#include <stdlib.h>

int my_atoi(const char *p)
{
	int neg;
	int ret = 0, n;

	if (*p == '-') {
		neg = -1;
		p++;
	} else {
		neg = 1;
	}

	while (*p >= '0' && *p <= '9') {
		n = *p - '0';
		if (neg == -1) {
			n = -n;
		}

		ret = ret*10 + n;
		p++;
	}

	return ret;
}
		
int main()
{
	char *p = "-1234";
	int n = my_atoi(p);

	printf("%d\n", n);
	
	return 0;
}
