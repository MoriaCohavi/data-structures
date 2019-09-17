#include "Queue_point.h"

void create_queue (queue *pq)
{
	pq->items_num = 0;
    pq->front = NULL;
    pq->rear = NULL;
}

int enqueue (queue_type x, queue *pq)
{   
	queue_element *temp = malloc(sizeof(queue_element));
	if (!temp)
		return 0;
	temp->data = x;
	temp->ptr_next = NULL;
	if (pq->items_num != 0)
	{
		pq->rear->ptr_next = temp;
		pq->rear = pq->rear->ptr_next;
	}
	else
		pq->front = pq->rear = temp;	
	pq->items_num++;
    return 1;
}

queue_type dequeue (queue *pq)
{
	queue_element *temp;
	queue_type item = NULL;

	if (pq->items_num == 0)
		return item;
	temp = pq->front;
    pq->front = temp->ptr_next;
	item = temp->data;
    free (temp);
	if (!pq->front) //if (pq->items_num == 1)
		pq->rear = NULL;
	pq->items_num--;
	return item;
}

int queue_front (queue *pq, queue_type *px)
{
	if (pq->items_num == 0)
		return 0;
	*px = pq->front->data;
	return 1;
}

int queue_is_empty (queue *pq)
{
	return pq->items_num == 0;
}

int queue_is_full (queue *pq)
{
	return 0;
}

int size_of_queue (queue *pq)
{
	return pq->items_num;
}











