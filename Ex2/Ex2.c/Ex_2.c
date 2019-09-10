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
	//Insert(lst1, 4, 2);
	//Insert(lst1, 6, 4);
	//Insert(lst1, 4, 3);
	//Insert(lst1, -4, 3);
	//Insert(lst1, 1, 1);
	//PrintPolList(lst1);

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
	printf("%d\n", Order(lst2));
	system("PAUSE");
}