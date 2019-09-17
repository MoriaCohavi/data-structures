#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include "BinaryTree.h"

Tree *Ex1(Tree *Root);
void Ex2(Tree *Root);
void Ex4(Tree *tree);


int main()
{
	Tree *Root = NULL;
	int exSelect = 0, ii, menuSelect = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &menuSelect) == 1)
		do
		{
			for (ii = 0; ii < 4; ii++)
				printf("Ex%d--->%d\n", ii + 1, ii + 1);
			printf("EXIT-->0\n");
			do {
				exSelect = 0;
				printf("please select 0-4: ");
				scanf("%d", &exSelect);
			} while ((exSelect < 0) || (exSelect > 5));
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

				}break;

				case 4:
				{
					Ex4(Root);
				}
			}
		} while (menuSelect && exSelect);

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

void Ex4(Tree *tree)
{
	if (tree)
	{
		freeTree(tree->RightSon);
		freeTree(tree->LeftSon);
		free(tree);
	}
}