/* 
 * the longest common subsquence problem is describled in "Introduction
 * to algorithms" in page 222.
 * 
 * here is my implementation in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char b[MAX][MAX];

/*
 * initialization first line and row to be 0
 *
 * time: O(mn)
 */
void lcs_length(char x[], char y[])
{
	int m, n, i, j;

	m = strlen(x);
	n = strlen(y);
	int c[m+1][n+1];

	for (i = 0; i <= m; i++)
		c[i][0] = 0;
	for (i = 0; i <= n; i++)
		c[0][i] = 0;
	
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			if (x[i-1] == y[j-1]) {
				c[i][j] = c[i-1][j-1] + 1;
				b[i][j] = '\\';
			}
			else if (c[i-1][j] >= c[i][j-1]) {
				c[i][j] = c[i-1][j];
				b[i][j] = '|';
			} else {
				c[i][j] = c[i][j-1];
				b[i][j] = '-';
			}
		}
	}

	for (i = 0; i <= m; i++) {
		for (j = 0; j <= n; j++)
			printf("%d%c  ", c[i][j], b[i][j]);
		printf("\n");
	}
}

void print_lcs(char x[], int i, int j)
{
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == '\\') {
		print_lcs(x, i-1, j-1);
		putchar(x[i-1]);
	}
	else if (b[i][j] == '|')
		print_lcs(x, i-1, j);
	else 
		print_lcs(x, i, j-1);
}


/* 这个只能left和right中最长的连续子串，对于LCS的经典定义的求解是不正确的*/
char *lcs(char left[], char right[])
{
	int llen = strlen(left), rlen = strlen(right), k;

	int *c = malloc(rlen);
	char *p;

	int start, end, len, i, j;
	end = len = 0;

	for (i = 0; i < llen; i++) {
		for (j = rlen-1; j >= 0; j--) {
			if (left[i] == right[j]) {
				if ( i == 0 || j == 0) 
					c[j] = 1;
				else {
					c[j] = c[j-1] + 1;
				}
			} else 
				c[j] = 0;

			if (c[j] > len) {
				len = c[j];
				end = j;
			}
			printf("%d  ", c[j]);
		}
		printf("\n");
	}

	start = end - len + 1;

	p = (char *) malloc(len + 1);
	for (i = start; i <= end; i++) {
		p[i - start] = right[i];
	}
	p[len] == '\0';
	return p;
}



int main()
{
	char x[] = "abcbdab";
	char y[] = "bdcaba";
	lcs_length(x, y);

	print_lcs(x, strlen(x), strlen(y));
	
//	char *p = lcs(x, y);
//	printf("%s\n", p);

	return 0;
}
