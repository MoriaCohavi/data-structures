//submitted by Moria Cohavi i.d. 312321698 and Keren Vieytes i.d. 312213176


#define _CRT_SECRE_NO_WARNINGS
#define MaxStack 50

typedef char stack_type;

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

typedef struct
{
	int top;
	stack_type items[MaxStack];
}	stack;

void create_stack(stack *);

int push(stack_type, stack *);

int pop(stack *, stack_type *);

int stack_top(stack *, stack_type *);

int stack_is_empty(stack *);

int stack_is_full(stack *);

int getInput(char *expression);// func that gets the user's input into a string and return the strings' size
int sortInput(char charToCheck); //sorts each char in the input. The number that returns represent the rule of the char.
int checkFirstCharacter(char first); // func for checking the first charcter of the arithmatic expression.
int checkExpression(char *expression, int size); // func that checks if the expression is legal.
int priorityOp(char operation1, char operation2);// func that for priority check two operations
int tablePresentation(char *expression, int size); //the function requested in the exercise.



PolynomialList *InitPolynomialList();
void Insert(PolynomialList *lst, int variable, int pow);
PolynomialList *Sum(PolynomialList *p1, PolynomialList *p2);
PolynomialList *Diff(PolynomialList *lst1, PolynomialList *lst2);
PolynomialList *Multiple(PolynomialList *lst, int scalar);
int Order(PolynomialList *lst);
PolynomialList *EmptyPol(PolynomialList *list);
void PrintPolList(PolynomialList *lst);
PolynomialList *Multi2Pol(PolynomialList *list1, PolynomialList *list2);