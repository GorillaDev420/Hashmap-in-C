#include <stdio.h>
#include <stdlib.h>
int main(){

	int i = 99;
	int* p = &i; //0x84353FFAA == int
	printf("%d\n", *p);
	printf("%p\n", p);

}
