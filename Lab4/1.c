#include <stdio.h>

int bits;

void p(int a);
void g();
void h();
void d();

int main(){
	bits = 10;

	p(5);
	g();
	h();
	d();

	printf("Address of bits(global): %u\n",&bits);
}

void p(int a){
	int pilani=1;
	printf("Address of pilani(p local): %u\n",&pilani);
	if(a==100) return;
	p(a+1);
}

void g(){
	int goa = 2;
	printf("Address of goa(g local): %u\n",&goa);
}

void h(){
	int hyd=3;
	printf("Address of hyd(h local): %u\n",&hyd);
}

void d(){
	int dub=4;
	printf("Address of dub(d local): %u\n",&dub);
}

//Stack space for different functions overlaps in the stack segment.
//The segment for glabal varaible is heap which has non-overlapping memory addresses with the stack segment.

/* Stack is allocated from the top of the segment towards downward direction */
