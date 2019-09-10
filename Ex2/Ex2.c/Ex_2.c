#define _CRT_SECURE_NO_WARNINGS

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
	int exSelect = 0, ii, menuSelect = 0, variable, pow, p1_size = 0, p2_size = 0, chooseList = 0, multi;

	PolynomialList *lst1 = InitPolynomialList();
	printf("Lets create the first Polinomial. How many organs would it be?\n");
	scanf_s("%d", &p1_size);

	if (p1_size > 0)
	{
		printf("Please insert [variable, power] for all organs, seperated by enters.\n");

		for (ii = 0; ii < p1_size; ii++)
		{
			scanf_s("%d%d", &variable, &pow);
			Insert(lst1, variable, pow);
		}
	}

	PolynomialList *lst2 = InitPolynomialList();
	printf("Lets create the second Polinomial. How many organs would it be?\n");
	scanf_s("%d", &p2_size);

	if (p2_size > 0)
	{
		printf("Please insert [variable, power] for all organs, seperated by enters.\n");

		for (ii = 0; ii < p2_size; ii++)
		{
			scanf_s("%d%d", &variable, &pow);
			Insert(lst2, variable, pow);
		}
	}

	printf("\nYour list are:\n");
	PrintPolList(lst1);
	PrintPolList(lst2);

	if (p1_size > 0 && p2_size > 0)//menu
	{
		printf("\nWhat would you like to do with the Polynomials?\n");
		printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number)");
		if (scanf("%d", &menuSelect) == 1)
			do
			{
				printf("\nAdd a new element to a polynom--->1\n");
				printf("Sum of the two polynoms--->2\n");
				printf("Subtraction of the two polynoms--->3\n");
				printf("Multiply a polinom with a number-->4\n");
				printf("Get highest power-->5\n");
				printf("Empty a polinom -->6\n");
				printf("Multiply a polinom with a polynom-->7\n");
				printf("EXIT-->0\n");
				do {
					exSelect = 0;
					printf("please select 0-7: ");
					scanf("%d", &exSelect);
				} while ((exSelect < 0) || (exSelect > 7));
				switch (exSelect)
				{
				case 1:
				{
					while (chooseList != 1 && chooseList != 2)
					{
						printf("To which polynom you want to add?\n");
						scanf("%d", &chooseList);
					}

					printf("Please insert [variable, power] for all organs, seperated by enters.\n");
					scanf("%d%d", &variable, &pow);
					if (chooseList == 1)
					{
						Insert(lst1, variable, pow);
						printf("Your new list is:\n");
						PrintPolList(lst1);
					}
					else
					{
						Insert(lst2, variable, pow);
						printf("Your new list is:\n");
						PrintPolList(lst2);
					}

				}break;
				case 2:
				{
					PolynomialList *lst3 = InitPolynomialList();
					lst3 = Sum(lst1, lst2);
					printf("The result is:\n");
					PrintPolList(lst3);

				}break;
				case 3:
				{
					PolynomialList *lst3 = InitPolynomialList();
					chooseList = 0;

					while (chooseList != 1 && chooseList != 2)
					{
						printf("Which polynom you want to subtract from?\n");
						scanf("%d", &chooseList);
					}
					
					if (chooseList == 1)
						lst3 = Diff(lst1, lst2);
					else
						lst3 = Diff(lst2, lst3);
					printf("The result is:\n");
					PrintPolList(lst3);
				}break;
				case 4:
				{
					PolynomialList *lst3 = InitPolynomialList();
					chooseList = 0;
					printf("Enter the number you want to multiply by:\n");
					scanf("%d", &multi);

					while (chooseList != 1 && chooseList != 2)
					{
						printf("Which polynom you want to multiply?\n");
						scanf("%d", &chooseList);
					}

					if (chooseList == 1)
						lst3 = Multiple(lst1, multi);
					else
						lst3 = Multiple(lst2, multi);

					printf("The result is:\n");
					PrintPolList(lst3);
				}break;
				case 5:
				{
					chooseList = 0;

					while (chooseList != 1 && chooseList != 2)
					{
						printf("Which polynom you want to check for highest power?\n");
						scanf("%d", &chooseList);
					}

					if (chooseList == 1)
						printf("The higehst power in list1 is:%d", Order(lst1));
					else
						printf("The higehst power in list2 is:%d", Order(lst2));

				}break;
				case 6:
				{
					chooseList = 0;

					while (chooseList != 1 && chooseList != 2)
					{
						printf("Which polynom you want to empty?\n");
						scanf("%d", &chooseList);
					}

					if (chooseList == 1)
						lst1 = EmptyPol(lst1);
					else
						lst2 = EmptyPol(lst2);
				}break;
				case 7:
				{
					PolynomialList *lst3 = InitPolynomialList();
					lst3 = Multi2Pol(lst1, lst2);

					printf("The result is:\n");
					PrintPolList(lst3);

				}break;
				}
			} while (menuSelect && exSelect);
			return 0;

	}

	system("PAUSE");
}