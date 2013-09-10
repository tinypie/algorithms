/* 
 * 字符串移位包含的问题：给定两个字符串S1和S2，要求判定S2能否被S1做循环移位得到的字符串包含。
 * 
 * 1. 例如S1=AABCD, S2=CDAA. 先将S1变成CDAAB，再判断S1是否包含S2.
 * 2. 判断S1S1是否包含S2
 * 3. 先从S1的S1[3] = C开始判断，S1[3,4] == S2[0,1],    S1[0,1]==S2[2,3]
 *
 * 题目出自《编程之美》P215 section 3.1
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_word(char *start, char *end)
{
	char tmp;

	while (start < end) {
		tmp = *start;
		*start = *end;
		*end = tmp;

		start++;
		end--;
	}
}

/* 
 * 找到S1中包含S2首字母的位置，再将S1做循环移位，最后判断S1是否包含S2.
 * 例如S1=AABCD, S2=CDAA. 先将S1变成CDAAB，再判断S1是否包含S2.
 */
int contained(char *s1, char *s2) 
{
	char *start, *end, *p;
	p = s1;

	while (*p != '\0' && *p != *s2) 
		p++;
	
	if (*p == '\0')
		return 0;	/* 不包含 */
	
	start = p;
	while (*p != '\0')
		p++;
	
	reverse_word(s1, start-1);
	reverse_word(start, p-1);
	reverse_word(s1, p-1);

	if (strncmp(s1, s2, strlen(s2)) == 0) 
		return 1;
	else 
		return 0;
}


int main()
{
	char s1[] = "aabcd";
	char s2[] = "cdaa";

	int i = contained(s1,s2);

	printf("%d\n", i);
	
	return 0;
}
