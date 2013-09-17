/*
 * 字符串的连接顺序
 *
 * "abdbcca"
 * "abc"
 * 第二个在第一个中的连接顺序为
 * 125， 126，145，146.
 *
 * 用递归方法
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void print_array(char *p, int p_len,
		 char *s, int s_len, 
		 int *array, int n, 
		 int p_start, int s_start)
{
	int tn, tp, ts;
	tn = n;
	tp = p_start;
	ts = s_start;

	if (n == s_len) {
		for (int i = 0; i < s_len; i++) {
			cout << *(array + i);
		}
		cout << endl;
		return;
	}

	for (int i = tp; i < p_len; i++) {
		for (int j = ts; j < s_len; j++) {
			if (*(p+i) == *(s+j)) {
				array[tn] = i+1;
				tp = i;
				ts = j;
				print_array(p, p_len, s, s_len,
					array, tn+1, tp+1, ts+1);
			}
		}
	}
}

void shun(char *p, char *s)
{
	int p_len = strlen(p);
	int s_len = strlen(s);
	int *array = new int[s_len];

	if (p == NULL || s == NULL) {
		cout<<"string error"<<endl;
	}

	if (array == NULL) {
		cout << "allocate error" << endl;
	}

	print_array(p, p_len, s, s_len, array, 0, 0, 0);

	delete array;

}

int main()
{
	char p[] = "abdbcca";
	char s[] = "abc";


	shun(p, s);

	return 0;
}


