#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int TaskId;
typedef int Priority;

struct node{
	TaskId tid;
	Priority p;
	struct node* next;
};

struct queue{
	struct node* head;
	struct node* tail;
	int length;
};

typedef struct queue Queue;
typedef struct node Task;

Queue newQ();
bool isEmptyQ(Queue q);
Queue delQ(Queue q);
Task frontQ(Queue q);
Queue addQ(Queue q, TaskId id, Priority pi);
Queue lengthQ(Queue q);
void printQ(Queue q);
