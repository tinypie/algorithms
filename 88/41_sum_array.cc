#include <iostream>
using namespace std;

bool find_sum(int *a, int len, int sum, int *num1, int *num2)
{
	if (a == NULL || len <= 0 || num1 == NULL || num2 == NULL)
		return false;
	
	int begin, end, cur;
	bool fd = false;
	begin = 0;
	end = len - 1;

	while (begin < end) {
		cur = a[begin] + a[end];
		if (sum == cur) {
			*num1 = a[begin];
			*num2 = a[end];
			fd = true;
			break;
		} else if (sum > cur) {
			begin++;
		} else 
			end--;
	}

	return fd;
}
			
void print(int small, int big)
{
	int i;
	for (i = small; i <= big; i++) {
		cout << i << "\t";
	}
	cout << endl;
}

void find_cont_sum(int sum)
{
	if (sum < 3)
		return ;
	
	int small, big, mid, cur;
	small = 1; 
	big = 2;
	mid = (1+sum) / 2;

	cur = small + big;

	while (small < mid) {
		if (cur == sum) {
			print(small, big);
		}

		while (cur > sum && small < mid) {
			cur -= small;
			small++;

			if (cur == sum) {
				print(small, big);
			}
		}
		big++;
		cur +=big;
	}

}

int main()
{
	find_cont_sum(9);
	return 0;
}
