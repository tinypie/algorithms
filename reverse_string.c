/* 
 * reverse a string. use a char space, which is called in-place reverse
 * another solution is using exclusive OR operator.
 */
#include <stdio.h>
#include <stdlib.h>

/* use one char space or we can use the '\0' */
char *reverse(char *s)
{
	char *p, *r;
	char t;
	r = p = s;
	while (*p++)
		;
	
	p -= 2;

	while (r < p) {
		t = *r;
		*r = *p;
		*p = t;
		r++;
		p--;
	}

	return s;
}

/* use exclusive OR operator to change to char*/
char *reverse_or(char *s)
{
	char *p, *r;
	p = r = s;
	while (*p++) ;
	p -= 2;

	while (r < p) {
		*r = *p ^ *r;
		*p = *p ^ *r;
		*r = *p-- ^ *r++;
	}

	return s;
}


/* 
 * reserve sentence problem. First reverse the single world, then reverse the 
 * sentence
 */

void reverse_word(char *p, char *q)
{
	char t;
	while(p < q) {
		t = *p;
		*p++ = *q;
		*q-- = t;
	}
}

char *reverse_sentence(char *s) {
	char *p, *q;

	p = q = s;

	while (*q) {

		if (*q == ' ') {
			reverse_word(p, q-1);
			p = ++q;
		} else {
			q++;
		}
	}

	reverse_word(p, q-1);
	reverse_word(s, q-1);
	return s;
}


int main()
{
	char s[14] = "hello word";
	printf("%s\n", s);

//	reverse_or(s);
	reverse_sentence(s);


	puts(s);
	return 0;
}
