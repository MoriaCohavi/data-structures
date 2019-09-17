#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include "BinaryTree.h"


int emptyTree(Tree *newtree)
{
	if (newtree == NULL)
		return 0;
	return 1;
}

int checkLeaf(Tree *newtree)
{
	if (!emptyTree(newtree))
		return 0;
	return (newtree->LeftSon == NULL && newtree->RightSon == NULL);
}

Tree *leftSon(Tree *newtree)
{
	if (!emptyTree(newtree))
		return 0;
	return newtree->LeftSon;
}

Tree *rightSon(Tree *newtree)
{
	if (!emptyTree(newtree))
		return 0;
	return newtree->RightSon;
}

Tree *parent (Tree *newtree)
{
	if (!emptyTree(newtree))
		return 0;
	return newtree->Parent;
}

tree_type nodeData (Tree *newtree)
{
	if (!emptyTree(newtree))
		return 0;
	return newtree->value;
}

void insertToTree(Tree **Root, Tree *parent, tree_type data)
{
	Tree *temp = NULL;

	if ((*Root) == NULL)
	{
		temp = (Tree *)malloc(sizeof(Tree));
		temp->LeftSon = temp->RightSon = NULL;
		temp->Parent = parent;
		temp->value = data;
		(*Root) = temp;
		return;
	}

	if (data > (*Root)->value)
	{
		insertToTree(&(*Root)->RightSon, *Root, data);
	}
	else if (data < (*Root)->value)
	{
		insertToTree(&(*Root)->LeftSon, *Root, data);
	}
}

void freeTree(Tree *deltree)
{
	if (deltree)
	{
		freeTree(deltree->RightSon);
		freeTree(deltree->LeftSon);
		free(deltree);
	}
	
}

