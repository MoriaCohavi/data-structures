#include <stdlib.h>
#include "doubly_list.h"
#include "polinomial_list.h"

void Ex_2();

void main()
{
	Ex_2();
}

void Ex_2()
{
	PolynomialList *lst1 = InitPolynomialList();
	Insert(lst1, 4, 0);
	Insert(lst1, -2, 4);
	Insert(lst1, 1, 0);
	Insert(lst1, 0, 1);
	Insert(lst1, 5, 1);
	Insert(lst1, -5, 1);
	Insert(lst1, 0, 0);
	Insert(lst1, 1, 1);
	Insert(lst1, 1, 9);
	Insert(lst1, 0, 9);
	Insert(lst1, 7, 0);
	PrintPolList(lst1);

	PolynomialList *lst2 = InitPolynomialList();
	Insert(lst2, 0, 2);
	Insert(lst2, 6, 8);
	Insert(lst2, 4, 3);
	Insert(lst2, -4, 3);
	Insert(lst2, 1, 1);
	PrintPolList(lst2);

	//PolynomialList *lst3 = InitPolynomialList();
	//lst3 = Sum(lst1, lst2);
	//lst3 = Diff(lst1, lst2);
	//lst3 = Multiple(lst2, 2);
	//PrintPolList(lst3);
	//lst1 = EmptyPol(lst2);
	//PrintPolList(lst1);
	//printf("%d\n", lst1);
	system("PAUSE");
}