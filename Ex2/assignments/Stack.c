//submitted by Moria Cohavi i.d. 312321698 and Keren Vieytes i.d. 312213176

#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"

#define _CRT_SECRE_NO_WARNINGS

void create_stack (stack *ps)
{
	ps->top = -1;
}

int push (stack_type x, stack *ps)
{
	if (ps->top < MaxStack-1)
	{
		ps->top++;
        ps->items[ps->top] = x;
        return 1;
	}
	return 0;
}

int pop (stack *ps, stack_type *px)
{
	if (ps->top >= 0)
	{
		*px = ps->items[ps->top];
        ps->top--;
        return 1;
	}
	return 0;
}

int stack_top (stack *ps, stack_type *px)
{
	if (ps->top >= 0)
	{
		*px = ps->items[ps->top];
        return 1;
	}
	return 0;
}

int stack_is_empty (stack *ps)
{
	return ps->top == -1;
}

int stack_is_full (stack *ps)
{
	return ps->top == MaxStack-1;
}

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