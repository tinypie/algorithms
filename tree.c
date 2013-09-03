/*
 * tree data structure
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * 层次遍历二叉树，也就是一层一层的遍历。
 * use queue structure
 *
void level_order(struct bst *t)
{
	struct bst *p;
	struct queue q;

	init_queue(q);
	entry_queue(q, t);

	while(!empty_queue(q)) {
		delete_queue(q,p);
		visit(p);

		if (p->leftchild != NULL) {
			entry_queue(q, p->leftchild);
		}
		if (p->rightchild != NULL) {
			entry_queue(q, p->rithchild);
		}
	}

}
 *
 */

/*
 * implement binary search tree
 * (BST)
 */

#define DataType int

struct bst {
	DataType key;
	struct bst *left;
	struct bst *right;
};

void destroy(struct bst **root)
{
 	if ((*root) != NULL && (*root)->left != NULL)
		destroy(&(*root)->left);

	if ((*root) != NULL && (*root)->right != NULL)
		destroy(&(*root)->right);
	
	free(*root);
}



void inorder_tree_walk(struct bst *root)
{
	if (root != NULL) {
		inorder_tree_walk(root->left);
		printf("%d\t", root->key);
		inorder_tree_walk(root->right);
	}
}

/* 
 * if key exits, then return a pointer points to it.
 * else, then return NULL
 */
struct bst *tree_search(struct bst *root, DataType key)
{
	if (root == NULL or root->key == key) {
		return root;
	}

	if (root->key > key) {
		return tree_search(root->left, key);
	} else {
		return tree_search(root->right, key);
	}
}

struct bst *tree_search_ite(struct bst *root, DataType key)
{
	struct bst *p;
	if (root != NULL) {
		p = root;
		while (p != NULL) {
			if (p->key == key)
				return p;
			else if (p->key > key)
				p = p->left;
			else
				p = p->right;
		}
	}

	return NULL;
}

		
/*
 * if succussfull return 1, if already exist return -1
 */
int tree_insert(struct bst **root, int key)
{
	struct bst *current, *parent, *p;
	parent = current = *root;

	/* find the position */
	while (current != NULL) {
		parent = current;		/* parent is the parent */
		if (current->key == key) 
			return -1;	/* already exist */
		else if (current->key > key) 
			current = current->left;
		else 
			current = current->right;
	}

	p = (struct bst *) malloc(sizeof(struct bst));
	p->key = key;
	p->left = p->right = NULL;

	if (parent == NULL) 		/* empty tree */
		*root = p;
	else if (key > parent->key) {
		parent->right = p;
	} else
		parent->left = p;
	
	return 1;
}

		
struct bst *tree_min(struct bst *root)
{
	while (root->left != NULL) {
		root = root->left;
	}

	return root;
}
		
struct bst *tree_max(struct bst *root)
{
	while (root->right != NULL) {
		root = root->right;
	}

	return root;
}

/*
 * delete a node(z) is a lot complicated. there are there cases.
 * 1. z has no child, simply delete it.
 * 2. z has one child, use z's child to replace it.
 * 3. z has two children, replace z as the z's successor y, which has no left child 
 * (Z的右子树中最小的结点，右子树中最左端的孩子）
 *    Z's right child tree to be y's right child tree, and Z's left tree to be
 *    y's left tree
 *    也就是用Z的直接后继替代Z
 */

struct bst *tree_delete(struct bst *root, int data)
{
	struct bst *tmp;

	if (root == NULL) 
		return NULL;
	
	if (root->key > data) {
		root->left = tree_delete(root->left, data);
	} else if (root->key < data) {
		root->right = tree_delete(root->right, data);
	} else {
		/*
		if (root->left && root->right) {
			tmp = tree_min(root->right);
			root->key = tmp->key;
			node->
		*/
		if (root->left == NULL) { 	/* case 1 */
			tmp = root->right;
			free(root);
			root = tmp;
		} else if (root->right == NULL) {
			tmp = root->left;
			free(root);
			root = tmp;
		} else {			/* case 3 */
			
			tmp = root->right;
			struct bst *parent = NULL;

			/* find the left most node of the tmp tree */
			while (tmp->left != NULL) {
				parent = tmp;
				tmp = tmp->left;
			}

			root->data = tmp->data;
			if (parent != NULL)
				parent->left = tree_delete(parent->left, parent->left->data);
			else
				root->right = tree_delete(root->right, root->right->data);
		}
	}

	return root;
}
				
/*
 * if succussfull return 1. if data doesn't exit return -1
 * 
 * root maybe changed 
 */
int tree_delete_ite(struct bst **root, DataType data) 
{
	struct bst *parent, *tmp;
	int flag = 0;

	/*
	 * 需要找到被删除节点的父节点，还要知道被删除节点是其父节点的
	 * 左孩子还是右孩子
	 * 如果flag == -1 是左孩子
	 * 如果falg == 1 是右孩子
	 */
	parent = NULL;
	tmp = *root;
	while (tmp != NULL) {
		if (tmp->key == data)
			break;
		else {
			parent = tmp;
			if (tmp->key > data) {
				tmp = tmp->left;
				flag = -1;
			} else {
				tmp = tmp->right;
				flag = 1;
			}
		}
	}

	if (tmp == NULL) {
		return -1;		/* 节点不存在 */
	}
	/* case 1，被删节点不存在左右孩子 */
	if (tmp->left == NULL && tmp->right == NULL) {
		if (parent == NULL) {	/* 是根节点，并且树只有一个根节点 */
			free(*root);
			*root = NULL;
			return 1;
		}
		if (flag == 1) {	/* 被删节点是其父节点的右孩子*/
			free(tmp);
			parent->right = NULL;
		} else if (flag == -1) {
			free(tmp);
			parent->left = NULL;
		}
	} else if (tmp->left != NULL && tmp->right == NULL) {
		if (flag == 1) {
			parent->right = tmp->left;
			free(tmp);
		} else if (flag == -1) {
			parent->left = tmp->left;
			free(tmp);
		}
	} else if (tmp->left == NULL && tmp->right == NULL) {
		if (flag == 1) {
			parent->right = tmp->right;
			free(tmp)
		} else if (flag == -1) {
			parent->left = tmp->right;
			free(tmp);
		}
	} else {	/* 左右孩子都有 */
		struct bst *p, *q;		

		p = tmp;
		q = tmp->right;

		while (q->left != NULL) {
			p = q;
			q = q->left;
		}
		
		tmp->key = q->key;

		if (q->right != NULL) {
			p->left = q->right;
		}
		free(q);
	}
	return 1;
}

