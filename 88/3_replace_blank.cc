#include <iostream>
#include <cstring>
using namespace std;

int replace_blank(char *str, int len)
{
	if (str == NULL || len <= 0)
		return -1;
	
	int num = 0;
	char *p1;
	int l1, l2;

	p1 = str;

	while (*p1 != '\0') {
		if (*p1 == ' ') {
			num++;
		}
		p1++;
	}
	
	l2 = strlen(str);
	l1 = l2 + num*2;
	if (l1+1 > len) 
		return -1;

	while (l2 != 0) {
		if (str[l2] != ' ') {
			str[l1--] = str[l2--];
		} else {
			str[l1--] = '0';
			str[l1--] = '2';
			str[l1--] = '%';
			l2--;
		}
	}

	return 0;
}
	
int main() 
{
	char str[30] = "hello word my ok";
	replace_blank(str, 30);

	cout << str <<endl;
	return 0;
}
