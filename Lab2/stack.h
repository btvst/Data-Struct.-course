#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

struct Stack{
	int capacity;
	linkedlist list;
};

typedef struct Stack stack;

stack newStack(int cap); //create a stack with capacity cap

int push(stack *s, int ele);
/* returns 1 if element successfuly pushed
 * return 0 if, -> stack is full */

node* pop(stack *s);

void printStack(stack *s);
