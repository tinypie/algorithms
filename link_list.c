/*
 * the opteration of link list,
 * the list has a head
 *
 * list_init() 
 * list_lenght()
 * list_search()
 * list_insert()
 * list_delete()
 * list_clear()
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define DATETYPE int

/* the struct of link list */
struct link_node {
	DATETYPE data;
	struct link_node *next;
};

void list_init(struct link_node **head)
{
	(*head) = (struct link_node *) malloc(sizeof(struct link_node));

	if (*head == NULL) {
		fprintf(stderr, "malloc error\n");
		exit(-1);
	}

	(*head)->next = NULL;
}

int list_clear(struct link_node **head)
{
	struct link_node *tmp, *np;
	tmp = *head;

	while (tmp != NULL) {
		np = tmp->next;
		free(tmp);
		tmp = np;
	}

	return 0;
}

/*
 * insert a node in the head of the list
 */
int list_insert(struct link_node *head, DATETYPE data)
{
	struct link_node *p;

	p = (struct link_node *)malloc(sizeof(struct link_node));
	if (p == NULL) {
		fprintf(stderr, "malloc (insert) error");
		exit(-1);
	}

	p->data = data;
	p->next = head->next;
	head->next = p;

	return 0;
}


/* insert a node in the ith position */
int list_insert_i(struct link_node *head, DATETYPE data, int i)
{
	int j = 0;
	struct link_node *tmp = head;
	struct link_node *p;

	/* find the (i-1)th position */
	while(tmp && j < i -1) {
		tmp = tmp->next;
		j++;
	}

	if (j != i - 1) 
		return 0;
	else {	
		p = (struct link_node *)malloc(sizeof(struct link_node));
		if (p == NULL) {
			fprintf(stderr, "malloc (insert) error");
			exit(-1);
		}

		p->data = data;
		p->next = tmp->next;
		tmp->next = p;
		return 1;
	}
}



		


		
int list_length(struct link_node *head)
{
	int i = 0;
	struct link_node *tmp = head;

	while (tmp->next != NULL) {
		i++;
		tmp = tmp->next;
	}

	return i;
}

/* 
 * delete a node where the node data is 'data'
 * if succussfull return 1, else return 0(mean the data does
 * not exist
 */
int list_delete(struct link_node *head, DATETYPE data)
{
	struct link_node *pre, *tmp;
	
	pre = head;
	tmp = head->next;
	while (tmp) {
		if (tmp->data == data) {
			break;
		}
		pre = tmp;
		tmp = tmp->next;
	}

	if (tmp == NULL) 	/* the data doesn't exist */
		return 0;
	else {
		pre->next = tmp->next;
		free(tmp);
		return 1;
	}
}

int main()
{
	struct link_node *head, *tmp;
	int i;

	list_init(&head);
	for (i = 0; i < 4; i++) {
		list_insert(head, i);
	}

	
	tmp = head->next;

	list_delete(head, 2);

	while(tmp) {
		printf("%d\t", tmp->data);
		tmp = tmp->next;
	}
	list_clear(&head);
		
	return 0;
}
