#include <iostream>
using namespace std;

struct binary_tree {
	int data;
	struct binary_tree *left;
	struct binary_tree *right;
};

//知道中序和后序，重建二叉树

struct binary_tree *reconstruct(int *preorder, int *inorder, int len)
{
	if (preorder == NULL || inorder == NULL || len <= 0) 
		return NULL;
	
	return construct(preorder, preorder+len-1, inorder, inorder+len-1);
}

struct binary_tree *construct( int *startp, int *endp, int *starti, int *endi)
{
	//建立根节点
	struct binary_tree *root = new struct binary_tree();
	root->data = startp[0];
	root->left = root->right = NULL;

	if (startp == endp) {
		if (starti == endi && *startp == *starti)
			return root;
		else
			throw exception("invalid input");
	} 
	
	int rootvalue = startp[0];
	int *rooti = starti;
	// 在中序中找到根节点
	while (rooti <= endi && *rooti != rootvalue)
		rooti++;
	if (rooti == endi && *rooti != rootvalue)
		throw exception("invalid input");
	
	int leftlen = rooti - starti;
	int *leftpe = startp+leftlen;

	if (leftlen > 0) {
		root->left = construct(startp+1, leftpe, starti, rooti-1);
	}
	if (leftlen < endp-startp) {
		root->right = construct(leftpe+1, endp, rooti+1, endi);
	}

	return root;
}

