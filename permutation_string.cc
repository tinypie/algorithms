/*
 * http://blog.csdn.net/Hackbuteer1/article/details/7462447
 * 实现字符的全排列如组合
 */

#include <iostream>
#include <cstring>
using namespace std;

bool is_swap(char *begin, char *end)
{
	char *p = begin;
	for (; p < end; p++) {
		if (*p == *end)
			return false;
	}

	return true;
}
void permutation(char *str, char *begin)
{
	if (*begin == '\0')
		cout << str << "\t";
	else {
		for (char *p =  begin; *p != '\0'; p++) {
			swap(*begin, *p);
			permutation(str, begin+1);
			swap(*begin, *p);
		}
	}
}

/* 
 * 组合
 */
/* 第一种递归，第二种位运算*/

void combination(char *str, int s, int n)
{
	int i;

	cout << "{";
	for (i = 0; i < n; i++) {
		if (s & (1 << i))
			cout << str[i];
	}

	cout << "}\n";
}
	
void wei(char *str)
{
	int n = strlen(str);
	for (int i = 1; i < (1 << n); i++) {
		combination(str, i, n);
	}
}

int main()
{
	char str[] = "abc";
	//permutation(str, str);
	//cout << endl << str << endl;
	wei(str);
	return 0;
}

