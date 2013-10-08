#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;


// 输入一个数n，按顺序输出从0到n位数
// 如n=3, 打印 0～999

//常规解
int print_chang(int n)
{
	int number = 1;
	while (n > 0) {
		number *= 10;
	 	n--;
	}

	for (int i = 0; i < n; i++) {
		cout << i << "\t";
	}
	return 0;
} // n is very large then crash

void print(char *num)
{
	bool is0 = true;
	int len = strlen(num);

	for (int i = 0; i < len; i++) {
		if (is0 && num[i] != '0') {
			is0 = false;
		}
		if (is0 == false) {
			putchar(num[i]);
		}
	}
	cout << "\t";
}

void print_ite(char *num, int len, int index)
{
	if (index == len - 1) {
		print(num);
		return ;
	}
	
	for (int i = 0; i < 10; i++) {
		num[index+1] = i + '0';
		print_ite(num, len, index+1);
	}
}

//转化成求 数字的排列
void print_n(int n)
{
	if (n <= 0)
		return;
	
	char *num = new char[n+1];
	num[n] = '\0';

	for (int i = 0; i < 10; i++) {
		num[0] = i + '0';
		print_ite(num, n, 0);
	}
	
	delete [] num;
}



int main()
{
	print_n(1);
	return 0;
}
