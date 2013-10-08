
//合并两个有序链表
//

struct list *merge(struct list *head1, struct list *head2)
{
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	
	struct list *pmerge == NULL;
	if (head1->data > head2->data) {
		pmerge = head1;
		pmerge->next = merge(head1->next, head2);
	} else {
		pmerge = head2;
		pmerge->next = merge(head1, head2->next);
	}

	return pmerge;
}


		
