#include <iostream>
using namespace std;
/*
 * 矩阵中每一行都是从小到大
 * 每一列也是从小到大
 * 从中找到某个数
 */

bool find(int *m, int row, int column, int num)
{
	if (m == NULL || row <= 0 || column <= 0)
		return false;
	
	int r,c;
	bool f = false;
	r = 0;
	c = column - 1;

	while (r < row && c >= 0) {
		 if (m[r*column+c] == num) {
		 	f = true;
			break;
		} else if (m[r*colum+c] > num) {
			c--;
		} else
			r++;
	}

	return f;
}

