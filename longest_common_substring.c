
/*
 * long common substring 
 * the string is continuous not like subsequous which the order is discontinuous
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * brute force 
 * time complexity O(M*N*L)
 *
 * m --> length of a
 * m --> length of b
 * l --> length of the longest common substring
 *
 */
int compare(char *a, char *b)
{
	int len = 0;

	while (*a && *b && *a++ == *b++)
		len++;
	
	return len;
}

int lcs_brute(char *a, char *b)
{
	int len, i, j;
	int max = 0, index = 0;

	for (i = 0; i < strlen(a); i++) {
		
		for (j = 0; j < strlen(b); j++) {
			len = compare(a+i, b+j);

			if (len > max) 
				max = len;
				index = i;
		}
	}

	return max;
}

/*
 * dynamic programming 
 *
 * dp[i][j] ===> 以x[i]和y[j]结尾的最长公共子串的长度
 *
 * dp[i][j] = dp[i-1][j-1] + 1   if x[i] == y[j]
 * dp[i][j] = 0			 if x[i] != y[j]
 *
 * initialization
 * dp[i][j] = 0 	if i==0 || j==0
 *
 * time : O(M*N)
 */
int lcs_dp(char *x, char *y)
{
	int i, j, m, n;
	int max = 0, index = 0;

	m = strlen(x);
	n = strlen(y);

	int dp[m][n];
	memset(&dp[0][0], 0, m*n*sizeof(int));

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (x[i] == y[j]) {
				if (i && j) {
					dp[i][j] =  dp[i-1][j-1] + 1;
				} 
				if (i == 0 || j == 0) {
					dp[i][j] = 1;
				}
				if (dp[i][j] > max) {
					max = dp[i][j];
				}
			}
			//printf("%d\t", dp[i][j]);
		}
		//printf("\n");
	}

	return max;
}
			
int main()
{
	char a[] = "aaaba";
	char b[] = "aabaa";

	printf("%d\n", lcs_brute(a, b));
	printf("%d\n", lcs_dp(a,b));
	return 0;
}
