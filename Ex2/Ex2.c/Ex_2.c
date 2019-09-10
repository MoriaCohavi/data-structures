#include <stdlib.h>
#include <stdio.h>
#include "polinomial_list.h"

void Ex_1();
void Ex_2();

void main()
{
	Ex_2();
}

void Ex_1()
{
}

void Ex_2()
{
	PolynomialList *lst1 = InitPolynomialList();
	PolynomialList *lst2 = InitPolynomialList();
	int variable;
	int pow;
	int p1_size = 0;
	int p2_size = 0;
	int i;

	printf("Lets create the first Polinomial. How many organs would it be?\n");
	scanf_s("%d", &p1_size);

	if (p1_size > 0)
	{
		printf("Please insert [variable, power] for all organs, seperated by enters.\n");

		for (i = 0; i < p1_size; i++)
		{
			scanf_s("%d%d", &variable, &pow);
			Insert(lst1, variable, pow);
		}
	}

	if (p2_size > 0)
	{
		printf("Lets create the second Polinomial. How many organs would it be?\n");
		scanf_s("%d", &p2_size);
		printf("Please insert [variable, power] for all organs, seperated by enters.\n");

		for (i = 0; i < p2_size; i++)
		{
			scanf_s("%d%d", &variable, &pow);
			Insert(lst2, variable, pow);
		}
	}

	if (p1_size > 0 && p2_size > 0)//menu
	{
		printf("What would you like to do with the Polynomials?");
	}

	PrintPolList(lst1);
	PrintPolList(lst2);
	system("PAUSE");
}