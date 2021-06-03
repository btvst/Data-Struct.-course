#include "multiQ.h"

int main(){
	int num;
	int op,ye;
	printf("Enter number of elements:\n");
	scanf("%d",&num);

	MultiQ mq=createMQ(num);
	do{
		printf("(1)Add task\n(2)Print MQ\n(3)Get highest priority front\n(4)Delete highest priority front\n(5)Check is MultiQ is empty\n(6)Get size of MultiQ\n(7)Get number of tasks with priority x\n(8)Get queue of tasks with priority X\n");
		scanf("%d",&op);

		switch(op){
			case 1:
				{
					Task t;
					printf("Enter task id and priority:\n");
					scanf("%d%d",&t.tid,&t.p);
					mq=addMQ(mq,t);
					break;
				}

			case 2:
				{
					printMQ(mq);
					break;
				}
			case 3:
			{
				Task t=nextMQ(mq);
				printf("Task ID:%d\nTask priority:%d\n",t.tid,t.p);
				break;
			}
			case 4:
			{
				mq=delNextMQ(mq);
				break;
			}
			case 5:
			{
				if(isEmptyMQ(mq))
					printf("Empty\n");
				else
					printf("Not Empty\n");
					
				break;
			}
			case 6:
				{
					printf("%d\n",mq.size);
					break;
				}
			case 7:
				{	
					Priority pr;
					printf("Enter reqd. priority:\n");
					scanf("%d",&pr);
					printf("Ans: %d\n",sizeMQbyPriority(mq,pr));
					break;
				}
			case 8:
				{
					Priority pr;
					printf("Enter reqd. priority:\n");
					scanf("%d",&pr);
					Queue q=getQueueFromMQ(mq,pr);
					printQ(q);
					break;
				}
			default:
				{
					printf("Enter valid option\n");
				}
		}

		printf("Perform op again(1-Yes/0-No)\n");
		scanf("%d",&ye);
	}while(ye != 0);
}
