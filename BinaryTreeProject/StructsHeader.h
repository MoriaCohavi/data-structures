#pragma once

typedef int tree_type ;

typedef struct Tree
{
	tree_type value;
	struct Tree *Parent;
	struct Tree *LeftSon;
	struct Tree *RightSon;
}Tree;

int emptyTree(Tree *newtree);
int checkLeaf(Tree *newtree);
Tree *leftSon(Tree *newtree);
Tree *rightSon(Tree *newtree);
Tree *parent(Tree *newtree);
tree_type nodeData(Tree *newtree);
void freeTree(Tree *deltree);


void insertToTree(Tree **Root, Tree *parent, tree_type data);


typedef Tree* queue_type;

typedef struct queue_element
{
	queue_type data;
	struct queue_element *ptr_next;
}	queue_element;

typedef struct
{
	queue_element *front, *rear;
	int items_num;
}	queue;

void create_queue(queue *);

int enqueue(queue_type, queue *);

queue_type dequeue(queue *);

int queue_front(queue *, queue_type *);

int queue_is_empty(queue *);

int queue_is_full(queue *);

int size_of_queue(queue *);