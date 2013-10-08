#include <iostream>
using namespace std;

struct link {
	int data;
	struct link *next;
};

void reverse_print(struct link *node) 
{
	if (node == NULL) {
		return;
	} else {
		reverse_print(node->next);
		cout << node->data << " ";
	}

}

