/*
 * 从1～N中找到和的M的组合
 */

#include <iostream>
#include <list>

using namespace std;

void find(int sum, int n)
{
	static list<int> ilist;

	if(n < 1 || sum < 1) 
		return;
	
	if (sum > n) {
		ilist.push_front(n);
		find(sum-n, n-1);
		ilist.pop_front();
		find(sum, n-1);
	} else {
		cout << sum;
		for (list<int>::iterator it = ilist.begin(); it != ilist.end(); it++) 
			cout << " " << *it;
		cout << endl;
	}
}

int main()
{
	int m, n;
	cout << "input the sum M:" ;
	cin >> m;
	cout << "input the 1~n N:";
	cin >> n;

	find(m, n);
	return 0;
}

