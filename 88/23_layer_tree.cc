#include <iostream>
#include <deque>
using namespace std;
struct tree {
	int data;
	struct tree *left;
	struct tree *right;
};

void top_bottom(struct tree *root)
{
	if (root == NULL)
		return ;
	
	deque <struct tree*> dt;

	dt.push_back(root);

	while (dt.size()) {
		struct tree *node = dt.front();
		dt.pop_front();

		cout << node->data;

		if (node->left) {
			dt.push_back(node->left);
		}

		if (node->right) {
			dt.push_back(node->right);
		}

	}
}
