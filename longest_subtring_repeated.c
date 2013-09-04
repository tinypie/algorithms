/*
 * http://dsqiu.iteye.com/blog/1701324
 * 最长重复子串问题
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * brute force ( 可重叠重复子串 ）
 * abcdabcda，这时最长重复子串是 abcda，中间的 a 是被重叠的
 */
int compare(char *a, char *b)
{
	int len = 0;
	while (*a && *b && *a++ == *b++) 
		len++;
	
	return len;
}

/*
 * O(n^3) include the compare O(n)
 */
int brute(char *str)
{
	char *tmp;
	int i, j, len;
	int max = 0, n;

	len = strlen(str);
	tmp = str;

	for (i = 0; i < len; i++) {
		for (j = i + 1; j < len; j++) {
			n = compare(&str[i], &tmp[j]);
			if (n > max) {
				max = n;
			}
		}
	}
	return max;
}

/*
 * KMP
 * PI[] array
 */

int kmp_pi(char *str, int *pi) 
{
	int k, max, i, n;

	n = strlen(str);

	pi[0] = -1;
	max = k = -1;

	for (i = 1; i < n; i++) {
		while (k > -1 && str[k+1] != str[i])
			k = pi[k];

		if (str[k+1] == str[i]) {
			k++;
			if (max < k) 
				max = k;
		}

		pi[i] = k;
	}
	
	/* 因为k是str[]的下标，所以max做为长度返回时，要+1 */
	return max+1;
} 

/* 	O(n^2) */
int kmp_repeated(char *str)
{
	int len, i, tmp, max = 0;
	int *pi;

	len = strlen(str);
	pi = (int *)malloc(len * sizeof(int));
	if (pi == NULL) 
		exit(-1);

	for (i = 0; i < len - 1; i++) {
		//memset(pi, 0, len*sizeof(int));
		tmp = kmp_pi(str+i, pi);
		if (tmp > max) {
			max = tmp;
		}
	}

	return max;
}
		
	
/*
 * 第三种是用后缀数组
 * 例如str[] = abcdabcda，后缀数组为
 * abcdabcda
 * bcdabcda
 * cdabcda
 * dabcda
 * abcda
 * bcda
 * cda
 * cd
 * a
 *
 * 然后对后缀数组进行排序
 * abcdabcda
 * abcda
 * a
 *
 * bcdabcda
 * bcda
 *
 * cdabcda
 * cda
 * cd
 *
 * dabcda
 * 最后求最大复杂子串
 */
int main()
{
	char str[] = "abcdabcda";

	printf("%d\n", brute(str));
	printf("%d\n", kmp_repeated(str));
	return 0;
}
