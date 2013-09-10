/*
 *			 preprocess time		matching time
 * Navie match			0			O((n-m+1)*m)
 * Rabin-karp			O(m)			O((n-m+1)*m)
 *
 * KMP				O(m)			O(n)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void naive_string_matcher(char *t, char *p)
{
	int m, s, n;

	n = strlen(t);
	m = strlen(p);
	
	for (s = 0; s < n -m; s++) {
		if (strncmp(t+s, p, m) == 0) {
			printf("Pattern occurs with shift %d\n", s);
		}
	}

}

int *compute_prefix_function(char *p, int psize)
{
	int k = -1, q;
	int *pi = (int *)malloc(sizeof(int)*psize);
	if (pi == NULL) 
		return NULL;
	
	pi[0] = k;
	for (q = 1; q < psize; q++) {
		while (k > -1 && p[k+1] != p[q])
			k = pi[k];

		if (p[k+1] == p[q])
			k++;
		pi[q] = k;
	}
	return pi;
}
		
int kmp_matcher(char *t, int tsize,  char *p, int psize) 
{
	int i, q = -1;
	int *pi = compute_prefix_function(p, psize);
	
	for (i = 0; i < psize; i++) 
		printf("%d\t", pi[i]);
	printf("\n");

	if (pi == NULL) 
		return -1;
	
	for (i = 0; i < tsize; i++) {
		while (q > -1 && p[q+1] != t[i]) 
			q = pi[q];
		if (t[i] == p[q+1])
			q++;

		if (q == psize - 1) {
			free(pi);
			return i-q;
		}
	}
	free(pi);
	return -1;
}

main()
{
	char t[] ="abadefde", p[]="bad";
	//naive_string_matcher(t,p);
	int i = kmp_matcher(t, strlen(t), p, strlen(p));
	printf("%d\n", i);
	return 0;
}
