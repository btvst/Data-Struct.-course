#include "multiQ.h"
#include <fcntl.h>
#include <unistd.h>

MultiQ loadFile(FILE* fptr, int line);
MultiQ testDel(int num);

int main(){
	FILE *fptr;
	fptr=fopen("input10.txt","r");

	MultiQ mq=loadFile(fptr,10);
	printMQ(mq);

	int num;
	printf("Enter no. of deletions:\n");
	scanf("%d",&num);

	MultiQ mq1=testDel(num);

	printMQ(mq1);
}


MultiQ loadFile(FILE *fptr, int line){
	int id,pr;
	if(fptr==NULL){
		printf("Error opening file\n");
		exit(1);
	}
	else{
		MultiQ mq=createMQ(line);
		Task t;

		while(fscanf(fptr,"%d,%d\n",&id,&pr) != EOF){
			t.tid=id;
			t.p=pr;
			printf("Task ID: %d\nPriority: %d\n",t.tid,t.p);
			mq=addMQ(mq,t);
		}

		return mq;
	}
}

MultiQ testDel(int num){
	FILE* fptr=fopen("input10.txt","r");
	printf("A\n");
	
	MultiQ mq = loadFile(fptr,10);
	printMQ(mq);

	for(int i=0; i<num; ++i){
		//printf("B\n");
		mq=delNextMQ(mq);
	}
	//printf("C\n");

	printMQ(mq);
	return mq;
}
