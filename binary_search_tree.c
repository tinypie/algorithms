#include <stdio.h>
#include <stdlib.h>

struct tree {
	int key;
	struct tree *parent; 
	struct tree *left;
	struct tree *right;
};


struct tree *tree_search(struct tree *node, int k)
{
	if (node = NULL || node->key == k) 
		return node;
	
	if (k < node->key)
		return tree_search(node->left, k);
	else
		return tree_search(node->right, k);
}


struct tree *tree_search_ite(struct tree *node, int k)
{
	struct tree *p;
	if (node != NULL) {
		p = node;
		while (p != NULL) {
			if (p->key == k) 
				return p;
			else if (p->key > k)
				p = p->left;
			else 
				p = p->right;
		}
	}
	return NULL;

#if 0
	while (node != NULL && node->key != k) {
		if (node->key > k) 
			node = node->left;
		else 
			node = node->right;
	}

	return node
#endif
}

struct tree *tree_minmum(struct tree *node)
{
	while (node->left != NULL) 
		node = node->left;
	
	return node;
}

struct tree *tree_maximum(struct tree *node)
{
	while (node->right != NULL) 
		node = node->right;
	
	return node;
}

struct tree *tree_successor(struct tree *node)
{
	struct tree *p;

	if (node->right != NULL) {
		return tree_minnum(node->right);
	}

	p = node->parent;
	while (p != NULL && node == p->right) {
		node = p;
		p = p->parent;
	}

	return p;
}

int tree_insert(struct tree **root, int k)
{
	struct tree *current, *parent, *p;

	current = *root;
	while (current  != NULL) {
		parent = current;
		if (current->key == k)
			return 0;
		if (current->key > k) 
			current = current->left;
		else
			current = current->right;
	}

	p = (struct tree *)calloc(1, sizeof(struct tree));
	p->key = k;
	p->parent = parent;

	if(parent == NULL) 
		*root = p;
	else if (k < parent->key)
		parent->left = p;
	else
		parent->right = p;
	
	return 1;
}
		


