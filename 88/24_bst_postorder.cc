//判断一个序列是不是 二叉搜索树的后序遍历序列
//

#include <iostream>
using namespace std;
bool verify(int *post, int len)
{
	if(post == NULL || len <= 0) 
		return false;
	
	int root = post[len-1];
	int i, j;	// i --> left

	for (i = 0; i < len - 1; i++) {
		if (post[i] > root)
			break;
	}

	for (j = i; j < len-1; j++) {
		if (post[j] < root)
			return false;
	}

	bool left = true;
	if (i > 0)
		left = verify(post, i);
	bool right = true;
	if (i < len-1)
		right = verify(post+i, len-i-1);
	return (left && right);
}
int main()
{
	int post[7] = {5, 7, 6, 9, 11, 10, 8};

	if (verify(post, 7))
		cout << "Yes"<<endl;
	else
		cout << "no" << endl;
	return 0;
}
