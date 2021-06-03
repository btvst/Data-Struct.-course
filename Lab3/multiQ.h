#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "que.h"

struct nodem{
       Queue qarr;
       Priority p;
       struct nodem* next;
};

typedef struct nodem NodeM;

struct multiq{
	NodeM* first;
	NodeM* last;
	int size;
};

typedef struct multiq MultiQ;

MultiQ createMQ(int num);
MultiQ addMQ(MultiQ mq,Task t);
Task nextMQ(MultiQ mq);
MultiQ delNextMQ(MultiQ mq);
bool isEmptyMQ(MultiQ mq);
int sizeMQ(MultiQ mq);
int sizeMQbyPriority(MultiQ mq,Priority p);
Queue getQueueFromMQ(MultiQ mq,Priority p);
MultiQ newMQ();
void printMQ(MultiQ mq);
