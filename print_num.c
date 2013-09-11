#include <stdio.h>
#include <stdlib.h>

void print_num(long n)
{
	if (n < 0) {
		putchar('-');
		n = -n;
	}

	if (n >= 16)
		print_num(n/16);
	putchar("0123456789abcdef"[n%16]);

}


void print2(long n)
{
	int i = 0;
	int r;
	char str[20]= "";

	while (n/10 != 0) {
		str[i] = n%10 + '0';
		i++;
		n = n/10;
	}

	str[i] = n%10 + '0';

	for (; i>=0; i--) 
		putchar(str[i]);
}


int main()
{
	long i = -53;
//	print_num(i);

	print2(35);

	putchar('\n');
	
	return 0;
}


