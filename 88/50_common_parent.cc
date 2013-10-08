#include <iostream>
#include <list>

using namespace std;

bool get_node_path(struct tree *root, struct tree *node, list <struct tree *> &path)
{
	if (root == node)
		return true;

	path.push_back(root);
	bool find = false;
	
	vecter<struct tree *>::iterator i = root->children.begin();

	while (!find && i < root->children.end()) {
		find = get_node_path(*i, node, path);
		i++;
	}

	if (find == false)
		path.pop_back(root);

	return find;	
}
{
	
struct tree *get_last(const list<struct tree *> &path1, const list<struct tree *> &path2)
{
	list<struct tree *>::iterator ite1 = path1.begin();
	list<struct tree *>::iterator ite2 = path2.begin();

	struct tree *node = NULL;
	
	while (ite1 != path1.end() && ite2 != path2.end()) {
		if (*ite1 == *ite2) {
			node = *ite1;
			break;
		}
		ite1++;
		ite2++;
	}

	return node;
}


struct tree *get_comon_parent(struct tree *root, struct tree *node1, struct *node2)
{
	if (root == NULL || node1 == NULL || node2 == NULL) {
		return NULL;
	}

	list<struct tree *> path1;
	get_node_path(root, node1, path1);

	list<struct tree *> path2;

	get_node_path(root, node2, path2);

	return get_last(path1, path2);
}
