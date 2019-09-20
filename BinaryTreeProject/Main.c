//submitted by Moria Cohavi i.d. 312321698 and Keren Vieytes i.d. 312213176

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include "StructsHeader.h"


Tree *Ex1(Tree *Root);
void Ex2(Tree *Root);//uses the tree Ex1 creates
void Ex3(Tree *tree);//uses the tree Ex1 creates
void Ex4(Tree *tree);//frees the tree Ex1 creates


int main()
{
	Tree *Root = NULL;
	int exSelect = 0, ii, menuSelect = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &menuSelect) == 1)
		do
		{
			for (ii = 0; ii < 3; ii++)
				printf("Ex%d--->%d\n", ii + 1, ii + 1);
			printf("EXIT-->0\n");
			do {
				exSelect = 0;
				printf("please select 0-3: ");
				scanf("%d", &exSelect);
			} while ((exSelect < 0) || (exSelect > 3));
			switch (exSelect)
			{
			case 1:
			{
				Root = Ex1(Root);
			}break;

			case 2:
			{
				Ex2(Root);
				printf("\n");
			}break;
			case 3:
			{
				Ex3(Root);
				printf("\n");
			}break;
			}
		} while (menuSelect && exSelect);

		system("PAUSE");
		Ex4(Root);
		return 0;
}

Tree *Ex1(Tree *Root)
{
	int num;
	if (Root != NULL)
	{
		Ex4(Root);
		Root = NULL;
	}

	printf("Enter the value you want to add to the tree. To stop enter -1\n");
	scanf("%d", &num);
	while (num != -1)
	{
		insertToTree(&Root, NULL, num);
		scanf("%d", &num);
	}

	printf("\n");
	return Root;
}

void Ex2(Tree *Root)
{
	Tree *current = NULL;
	Tree *previous = NULL;

	if (Root == NULL)
	{
		printf("The Tree is empty.\n");
		return;
	}


	current = Root;
	while (current != NULL)
	{
		if (current->LeftSon == NULL)
		{
			printf("[%d] ", current->value);
			current = current->RightSon;
		}
		else
		{
			previous = current->LeftSon;
			while (previous->RightSon != NULL && previous->RightSon != current)
				previous = previous->RightSon;

			if (previous->RightSon == NULL)
			{
				previous->RightSon = current;
				current = current->LeftSon;
			}

			else
			{
				previous->RightSon = NULL;
				printf("[%d] ", current->value);
				current = current->RightSon;
			}
		}
	}
}

void Ex3(Tree *tree)
{
	queue *pq = (queue*)malloc(sizeof(queue));
	create_queue(pq);
	Tree *temp = (Tree*)malloc(sizeof(Tree));
	int i;

	if (emptyTree(tree))
	{
		enqueue(tree, pq);

		while (!queue_is_empty(pq))
		{
			int currLen = pq->items_num;
			for (i = 0; i < currLen; i++)
			{
				temp = dequeue(pq);
				printf("%d ", temp->value);

				if (temp->LeftSon)
				{
					enqueue(temp->LeftSon, pq);
				}

				if (temp->RightSon)
				{
					enqueue(temp->RightSon, pq);
				}
			}
		}
	}

	else
	{
		printf("The tree is empty");
	}

	printf("\n");
}

void Ex4(Tree *tree)
{
	if (tree)
	{
		freeTree(tree->RightSon);
		freeTree(tree->LeftSon);
		free(tree);
	}
}
