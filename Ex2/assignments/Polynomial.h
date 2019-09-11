typedef int list_type1;

typedef struct polynomial {
	struct polynomial *next;
	struct polynomial *prev;
	list_type1 variable;
	list_type1 pow;
}Polynomial;

typedef struct polynomialList
{
	Polynomial *head;
	Polynomial *tail;
}PolynomialList;


PolynomialList *InitPolynomialList();

void Insert(PolynomialList *lst, int variable, int pow);

PolynomialList *Sum(PolynomialList *p1, PolynomialList *p2);

PolynomialList *Diff(PolynomialList *lst1, PolynomialList *lst2);

PolynomialList *Multiply(PolynomialList *lst, int scalar);

int Order(PolynomialList *lst);

PolynomialList *EmptyPol(PolynomialList *list);

void PrintPolList(PolynomialList *lst);

PolynomialList *Multi2Pol(PolynomialList *list1, PolynomialList *list2);