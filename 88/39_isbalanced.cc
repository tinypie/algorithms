#include <iostream>
using namespace std;

bool is_balanced(struct tree *node, int *depth)
{
	if (node == NULL) {
		*depth = 0;
		return true;
	}

	int left, right;
	if (is_balanced(node->left, &left) && is_balanced(node->right, &right)) {
		int diff = left - right;
		if (diff >= -1 && diff <= 1) {
			*depth = 1 + (left > right ? left : right);
			return true;
		}
	}
	
	return false;
}

bool balanced(struct tree *node) 
{
	int dep = 0;

	return is_balanced(node, &dep);
}
	
