#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include "BinaryTree.h"

void Ex1();

void main()
{
	Ex1();
}

void Ex1()
{
	int num;
	Tree *Root = NULL;

	printf("Enter the value you want to add to the tree. To stop enter -1\n");
	scanf("%d", &num);
	while (num != -1)
	{
		insertToTree(&Root, NULL, num);
		scanf("%d", &num);
	}

	deleteTree(Root);
	system("PAUSE");
}
