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

