#include "stack.h"

stack newStack(int cap){
	stack s;
	s.capacity = cap;
	s.list = newll();

	return s;
}

int push(stack *s, int ele){
	if(s->list.count == s->capacity){
		return 0;
	}

	else{
		insertFirst(&(s->list), ele);
	}
}

node* pop(stack *s){
	node *ans = deleteFirst(&(s->list));

	return ans;
}

void printStack(stack *s){
	printList(&(s->list));
}
