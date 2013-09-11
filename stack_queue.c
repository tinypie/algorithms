/*
 * the simplest way to create stack is use
 * globle variables. and int a[n], top. like
 *
 * #define SIZE 30
 *
 * int a[SIZE];
 * int top = -1;
 *
 *	push stack 
 *		a[++top] = data
 *	pop stack
 *		a[top--] 
 *	length is 
 *		top + 1
 */

#include <stdio.h>
#include <stdlib.h>


/* 
 * implement queue
 * 少用一个存储单元，解决假溢出。
 *
 * if full 
 * 	(tail + 1) % size == head
 * if empty
 * 	head == tail
 */

#define DataType int
#define MAX 30

struct queue {
	DataType data[MAX];
	int head;
	int tail;
};

int entry_queue(struct queue *q, DataType x) 
{
	if (q->tail + 1 == q->head) {
		printf("the queue is full\n");
		return 0;
	}
	q->data[q->tail] = x;

	q->tail = (q->tail + 1) % MAX;
	return 1;
}

int delete_queue(struct queue *q, DataType *x) 
{	
	if (q->head == q->tail) {
		printf("the queue is empty");
		return 0;
	}

	*x = q->data[q->head];
	q->head = (q->head + 1) % MAX;

	return 1;
}





