//submitted by Moria Cohavi i.d. 312321698 and Keren Vieytes i.d. 312213176


#define _CRT_SECRE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include "Structs.h"



int getInput(char *expression)
{
	int ii = 0, size = 0;
	char temp;

	temp = getchar();//get's the /n char that is left after the menu
	temp = getchar();

	while (temp != '\n')
	{
		if (temp != ' ')
		{
			expression[ii++] = temp;
			size++;
		}
		temp = getchar();
	}
	return size;
}

int sortInput(char charToCheck)
{
	if (charToCheck == '*' || charToCheck == '+' || charToCheck == '/' || charToCheck == '-' || charToCheck == '^')
		return 2;
	if (charToCheck >= '0' && charToCheck <= '9' || charToCheck >= 'A' && charToCheck <= 'H')
		return 3;

	return 0;
}

int checkFirstCharacter(char first)
{
	int value = -1;
	value = sortInput(first);
	if (value == 0)
		return 0;

	if (value == 2)
		return 0;

	return value;
}

int checkExpression(char *expression, int size)
{
	char cur, next;
	int ii = 0, cValue = -1, nValue = -1;

	if (size < 3)
	{
		printf("You didn't enter enough arguments.\n");
		return 0;
	}

	while (ii < size - 1)
	{
		if (ii == 0)
		{
			cur = expression[ii];
			cValue = checkFirstCharacter(cur);
			next = expression[ii + 1];
			nValue = sortInput(next);

			if (cValue == 0 || (nValue == 2 && cValue != 3) || cValue == nValue || ii == size || nValue == 0)
			{
				printf("You entered an illegal expression.\n");
				return 0;
			}
			ii++;
		}
		else
		{
			cur = next;
			cValue = nValue;
			next = expression[ii + 1];
			nValue = sortInput(next);
			ii++;

			if (cValue == 0 || cValue == nValue || nValue == 0)
			{
				printf("You entered an illegal expression.\n");
				return 0;
			}


		}
	}

	if (nValue == 2)
	{
		printf("You entered an illegal expression.\n");
		return 0;
	}

	return 1;
}

int priorityOp(char operation1, char operation2)
{
	if (operation1 == '^')
	{
		if (operation2 != '^')
			return 1;
		else
			return 0;
	}

	if (operation1 == '*' || operation1 == '/')
	{
		if (operation2 == '^')
			return -1;
		if (operation2 == '+' || operation2 == '-')
			return 1;
		return 0;
	}

	if (operation1 == '+' || operation1 == '-')
	{
		if (operation2 == '+' || operation2 == '-')
			return 0;
		return -1;
	}
}

int tablePresentation(char *expression, int size)
{
	stack S1;
	stack S2;
	int ii = 0, jj = 0, cSorting, opCheck = 3, sortingValue = 0;
	stack_type opPrev, orig1, orig2;

	char newch;

	sortingValue = checkExpression(expression, size);

	if (sortingValue == 0)
		return 0;

	create_stack(&S1);
	create_stack(&S2);

	printf("Operation \t Operand \t Operand2 \t Result\n");

	for (ii = 0; ii < size; ii++)
	{
		cSorting = sortInput(expression[ii]);
		if (cSorting == 3)
		{
			if (!(push(expression[ii], &S1)))
			{
				printf("There was an error with the Push func\n");
				return 0;
			}
		}

		if (cSorting == 2)
		{
			if (stack_is_empty(&S2))
			{
				if (!(push(expression[ii], &S2)))
				{
					printf("There was an error with the Push func\n");
					return 0;
				}
			}

			else
			{
				if (!(stack_top(&S2, &opPrev)))
				{
					printf("There was an error with the Top func\n");
					return 0;
				}

				opCheck = priorityOp(expression[ii], opPrev);
				if (opCheck >= 0)
				{
					if (!(push(expression[ii], &S2)))
					{
						printf("There was an error with the Push func\n");
						return 0;
					}
				}

				else
				{
					while (!stack_is_empty(&S2) && opCheck < 0)
					{
						if (!(pop(&S1, &orig2)))
						{
							printf("There was an error with the Pop func\n");
							return 0;
						}

						if (!(pop(&S1, &orig1)))
						{
							printf("There was an error with the Pop func\n");
							return 0;
						}

						if (!(pop(&S2, &opPrev)))
						{
							printf("There was an error with the Pop func\n");
							return 0;
						}

						newch = 90 - jj;
						jj++;

						if (!(push(newch, &S1)))
						{
							printf("There was an error with the Push func\n");
							return 0;
						}

						printf("%9c \t %7c \t %8c \t %6c\n", opPrev, orig1, orig2, newch);
						if (!stack_is_empty(&S2))
						{
							if (!(stack_top(&S2, &opPrev)))
							{
								printf("There was an error with the Top func\n");
								return 0;
							}
							opCheck = priorityOp(expression[ii], opPrev);
						}
					}

					if (!(push(expression[ii], &S2)))
					{
						printf("There was an error with the Push func\n");
						return 0;
					}

				}

			}
		}
	}

	while (!stack_is_empty(&S2))
	{
		if (!(pop(&S1, &orig2)))
		{
			printf("There was an error with the Pop func\n");
			return 0;
		}

		if (!(pop(&S1, &orig1)))
		{
			printf("There was an error with the Pop func\n");
			return 0;
		}

		if (!(pop(&S2, &opPrev)))
		{
			printf("There was an error with the Pop func\n");
			return 0;
		}

		newch = 'Z' - jj;
		jj++;
		if (!(push(newch, &S1)))
		{
			printf("There was an error with the Push func\n");
			return 0;
		}

		printf("%9c \t %7c \t %8c \t %6c\n", opPrev, orig1, orig2, newch);
	}

	return 1;
}


void create_stack(stack *ps)
{
	ps->top = -1;
}

int push(stack_type x, stack *ps)
{
	if (ps->top < MaxStack - 1)
	{
		ps->top++;
		ps->items[ps->top] = x;
		return 1;
	}
	return 0;
}

int pop(stack *ps, stack_type *px)
{
	if (ps->top >= 0)
	{
		*px = ps->items[ps->top];
		ps->top--;
		return 1;
	}
	return 0;
}

int stack_top(stack *ps, stack_type *px)
{
	if (ps->top >= 0)
	{
		*px = ps->items[ps->top];
		return 1;
	}
	return 0;
}

int stack_is_empty(stack *ps)
{
	return ps->top == -1;
}

int stack_is_full(stack *ps)
{
	return ps->top == MaxStack - 1;
}



PolynomialList *InitPolynomialList()
{
	PolynomialList *lst = (PolynomialList *)malloc(sizeof(PolynomialList));

	if (lst)
	{
		lst->head = lst->tail = NULL;
		return lst;
	}

	return NULL;
}

void Insert(PolynomialList *lst, int variable, int pow)
{
	Polynomial *iter = lst->head;
	Polynomial *plm = (Polynomial*)malloc(sizeof(Polynomial));

	if (plm)
	{
		plm->next = plm->prev = NULL;
		plm->pow = pow;
		plm->variable = variable;


		if (!lst->head)
		{
			lst->head = lst->tail = plm;
			return;
		}

		if (plm->pow < iter->pow)//if plm needs to be placed as head
		{
			Polynomial *temp = lst->head;
			lst->head = plm;
			plm->next = temp;
			temp->prev = plm;
			return;
		}

		while (iter)//if plm needs to be placed at the middle of the list
		{
			if (plm->pow == iter->pow)
			{
				if ((plm->variable + iter->variable) == 0)
				{
					if (!(iter->prev))//head
					{
						Polynomial *temp = lst->head;
						iter = lst->head = iter->next;
						iter->prev = NULL;
						free(temp);
					}

					else if (!(iter->next))//tail
					{
						Polynomial *temp = lst->tail;
						iter = lst->tail = iter->prev;
						iter->next = NULL;
						free(temp);
						return;
					}

					else
					{
						(iter->prev)->next = iter->next;
						(iter->next)->prev = iter->prev;
						free(iter);
					}

					return;
				}

				iter->variable += plm->variable;
				return;
			}

			if ((plm->pow < iter->pow))
			{
				Polynomial *temp = iter->prev;
				(iter->prev) = plm;
				temp->next = plm;
				plm->prev = temp;
				plm->next = iter;
				return;
			}

			if (!iter->next)//if plm needs to be placed as tail
			{
				plm->prev = iter;
				iter->next = plm;
				lst->tail = plm;
				return;
			}

			iter = iter->next;
		}
	}

	return NULL;
}


PolynomialList *Sum(PolynomialList *p1, PolynomialList *p2)
{
	PolynomialList *result_lst = InitPolynomialList();
	Polynomial *iter1 = p1->head;
	Polynomial *iter2 = p2->head;

	while (iter1)
	{
		Insert(result_lst, iter1->variable, iter1->pow);
		iter1 = iter1->next;
	}

	while (iter2)
	{
		Insert(result_lst, iter2->variable, iter2->pow);
		iter2 = iter2->next;
	}
		
	return result_lst;
}


PolynomialList *Diff(PolynomialList *p1, PolynomialList *p2)
{
	PolynomialList *result_lst = InitPolynomialList();
	Polynomial *iter1 = p1->head;
	Polynomial *iter2 = p2->head;

	while (iter1)
	{
		Insert(result_lst, iter1->variable, iter1->pow);
		iter1 = iter1->next;
	}

	while (iter2)
	{
		Insert(result_lst, -(iter2->variable), iter2->pow);
		iter2 = iter2->next;
	}

	return result_lst;
}

PolynomialList *Multiple(PolynomialList *lst, int scalar)
{
	PolynomialList *result_lst = InitPolynomialList();
	Polynomial *iter = lst->head;

	while (iter && scalar != 0)
	{
		Insert(result_lst, (iter->variable)*scalar, iter->pow);
		iter = iter->next;
	}

	return result_lst;
}

int Order(PolynomialList *lst)
{
	if (!lst->head)
		return -1;

	Polynomial *iter = lst->head;

	while (iter)
	{
		if (!iter->next)
			return iter->pow;
		iter = iter->next;
	}
}

PolynomialList *EmptyPol(PolynomialList *lst)
{
	Polynomial *head = lst->head;

	if (!head)
	{
		return lst;
	}

	Polynomial *ptr = lst->head;
	 
	while (ptr)
	{
		Polynomial *temp = ptr;
		ptr = ptr->next;
		free(temp);
	}

	lst->head = lst->tail = NULL;
	return lst;
}

void PrintPolList(PolynomialList *lst)
{
	if (!lst->head)
	{
		printf("Zero (Empty Polynomial)\n");
	}

	else
	{
		Polynomial *iter = lst->head;

		if (iter->variable > 0)//head
		{
			if (iter->pow == 0)
			{
				if (iter->variable == 1)
				{
					printf("1 ");
				}

				else
				{
					printf("%d ", iter->variable);
				}
			}

			else if (iter->pow == 1)
			{
				if (iter->variable == 1)
				{
					printf("x ");
				}

				else
				{
					printf("%d ", iter->variable);
				}
			}

			else
			{
				if (iter->variable == 1)
				{
					printf("x^%d ", iter->pow);
				}

				else
				{
					printf("%dx^%d ", iter->variable,iter->pow);
				}
			}

			iter = iter->next;
		}

		while (iter)
		{
			if (iter->variable > 0)
			{
				if (iter->pow == 0)
				{
					if (iter->variable == 1)
					{
						printf("+ 1 ");
					}

					else
					{
						printf("+ %d ", iter->variable);
					}
				}

				else if (iter->pow == 1)
				{
					if (iter->variable == 1)
					{
						printf("+ x ");
					}

					else
					{
						printf("+ %d ", iter->variable);
					}
				}

				else
				{
					if (iter->variable == 1)
					{
						printf("+ x^%d ", iter->pow);
					}

					else
					{
						printf("+ %dx^%d ", iter->variable, iter->pow);
					}
				}
			}

			else if (iter->variable < 0)
			{
				if (iter->pow == 0)
				{
					if (iter->variable == -1)
					{
						printf("- 1 ");
					}

					else
					{
						printf("%d ", iter->variable);
					}
				}

				else if (iter->pow == 1)
				{
					if (iter->variable == -1)
					{
						printf("- x ");
					}

					else
					{
						printf("%d ", iter->variable);
					}
				}

				else
				{
					if (iter->variable == -1)
					{
						printf("- x^%d ", iter->pow);
					}

					else
					{
						printf("%dx^%d ", iter->variable, iter->pow);
					}
				}
			}

			iter = iter->next;
		}

		printf("\n");
	}
}

PolynomialList *Multi2Pol(PolynomialList *list1, PolynomialList *list2)//Bonus
{
	PolynomialList *result_list = InitPolynomialList();
	Polynomial *lst1Ptr = list1->head;
	Polynomial *lst2Ptr = list2->head;
	Polynomial *lst2head = list2->head;
	int MultiBase, MultiPow;

	if (list1 == NULL || list2 == NULL)
	{
		printf("One of the list is empty, cant mulitply\n");
		return NULL;
	}

	while (lst1Ptr)
	{
		MultiBase = lst1Ptr->variable;
		MultiPow = lst1Ptr->pow;

		while (lst2Ptr)
		{
			if (MultiBase != 0 && lst2Ptr->variable != 0)
			{
				if (MultiPow == lst2Ptr->pow)
					Insert(result_list, (MultiBase*(lst2Ptr->variable)), MultiPow);
				else
				{
					Insert(result_list, (MultiBase*(lst2Ptr->variable)), (MultiPow + (lst2Ptr->pow)));
				}
			}
			lst2Ptr = lst2Ptr->next;
		}

		lst2Ptr = lst2head;
		lst1Ptr = lst1Ptr->next;
	}

	return result_list;
}
