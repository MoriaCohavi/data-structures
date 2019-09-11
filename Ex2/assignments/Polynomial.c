//submitted by Moria Cohavi i.d. 312321698 and Keren Vieytes i.d. 312213176

#include <stdlib.h>
#include <stdio.h>
#include "Polynomial.h"

#define _CRT_SECRE_NO_WARNINGS

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

PolynomialList *Multiply(PolynomialList *lst, int scalar)
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
