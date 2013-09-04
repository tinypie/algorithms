/*
 * longest substring without repeated
 *
 * dynamic programming
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * O(n^2) use a hash table. like brute force
 * max = max{len{a[i, j]} | 0 <= i < j < n }
 *
 */
int lsnr_brute(char *str)
{
	int size, i, j, max = 1;

	char hash[256];

	size = strlen(str);

	for (i = 0; i < size; i++) {
		memset(hash, 0, sizeof(hash));

		hash[str[i]] = 1;
		for (j = i+1; j < size; j++) {
			if (hash[str[j]] == 0) {
				hash[str[j]] = 1;
			} else {
				max = max > (j-i) ? max : (j-i);
				break;
			}
		}
		/* a[i, j],  if all the characters differ */
		if (j == size && (j-i) > max) {
			max = j-i;
		}
			

	}
	
	return max;
}

/* 
 * dynamic programming 
 * O(n^2)
 *
 * Optimal substructure 最大不重复子串一定是两个相同字符夹着的一段字符串加上这个字符，如abcac这里的最大不重复子串是a夹的一段
 * dp[i] 保存的是以a[i]结尾的最长不重复子串
 * 如果新的子串下标在上一个最长子串起始位置之前，则dp[i] = dp[i-1] + 1
 */
int lsnr_dp(char *str)
{
	int *dp, i, j;
	int last_start = 0, max = 0, index = 0;
	int size = strlen(str);

	dp = (int *) malloc(size*sizeof(int));
	if (dp == NULL)
		exit(-1);
	
	dp[0] = 1;
	for (i = 1; i < size; i++) {
		
		for (j = i-1; j >= last_start; j--) {
			if (str[i] == str[j]) {
				dp[i] = i-j;
				last_start = j+1;
				break;
			} else if (j == last_start) {
				dp[i] = dp[i-1] + 1;
			}
		}
		if (dp[i] > max) {
			max = dp[i];
			index = i-max+1;
		}
	}
	free(dp);

	return max;
}


/* 
 * dynamic programming and hash
 * time O(n) and space O(n) --> dp array and hash O(1) --> 256
 * 
 * not the optimal
 *
 * hash表记录的是，字符在字符数组中出现的下标
 */
int lsnr_dp_hash(char *str)
{
	char hash[256];
	int size, i;
	int last_start = 0, max = 0;
	int *dp;

	size = strlen(str);

	dp = (int *)malloc(size * sizeof(int));

	memset(hash, -1, sizeof(hash));
	memset(dp, 0, size * sizeof(int));

	dp[0] = 1;
	hash[str[0]] = 0;

	for (i = 1; i < size; i++) {
		if (hash[str[i]] == -1) {	/* haven't appeared */
			dp[i] = dp[i-1] + 1;
			hash[str[i]] = i;
		} else {
			if (last_start <= hash[str[i]]) {
				dp[i] = i - hash[str[i]];
				last_start = hash[str[i]] + 1;
				hash[str[i]] = i;
			} else {
				dp[i] = dp[i-1] + 1;
			}
		}

		if (dp[i] > max)
			max = dp[i];
	}

	return max;
	
	free(dp);
}
			
/*
 * dynamic programming and hash function with optimization
 *
 * time O(n)
 * space o(1) --> hash table
 */

int lsnr_dp_hash_opt(char *str)
{
	int i, size, curlen = 1;
	int max, last_start;
	char hash[256];

	max = last_start = 0;
	memset(hash, -1, sizeof(hash));

	hash[str[0]] = 0;
	size = strlen(str);

	for (i = 1; i < size; i++) {
		if (hash[str[i]] == -1) {
			curlen++;
			hash[str[i]] = i;
		} else {
			if (last_start <= hash[str[i]]) {
				curlen = i - hash[str[i]];
				last_start = hash[str[i]] + 1;
				hash[str[i]] = i;
			} else {
				curlen++;
				last_start = i;
			}
		}

		if (curlen > max) {
			max = curlen;
		}
	}

	return max;
}

int main()
{
	char str[] = "abdefab";

//	printf("%d\n", lsnr_brute(str));
//	printf("%d\n", lsnr_dp(str));
//	printf("%d\n", lsnr_dp_hash(str));
	printf("%d\n", lsnr_dp_hash_opt(str));
	return 0;
}
