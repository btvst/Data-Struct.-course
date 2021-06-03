#include <stdio.h>

int main(int argc, char *argv[]){
	FILE *src;
	FILE *dst;

	char str[1000]; //create buffer space for lines 
	char nl = '\n';

	src = fopen(argv[1], "r");
	dst = fopen(argv[2], "w");
	
	while(fscanf(src,"%[^\n]\n",str)!=EOF){ //scan until \n is obtained
		//Then ]\n puts the pointer to the next line
		printf("%s",str);
		fprintf(dst,"%s",str); 
		fprintf(dst,"%c",nl); //write into file2 '\n' after each line
	}

	fclose(src);
	fclose(dst);
}
