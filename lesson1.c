#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int first(char*);
int second(char**);

void main(){
	char c = 'c';
	first(&c);
	char namn[] = "Matty";
	first(&namn[0]);
	char* namn2[] = {"Matty", "Jatta", "Lejon"};
	first(namn2);
	second(namn2);
}

int first(char* letter){
	char* adr = &letter;
	char** same_adr = &letter;
	char*** pointer_to_pointer_to_another_pointer_wtf = &letter;
	printf("adress: %p\n", adr);
	printf("adress is still: %p\n", same_adr);
	printf("adress is once again: %p\n", pointer_to_pointer_to_another_pointer_wtf);
	printf("letter is %c\n", *letter);
	return 1;
}

int second(char ** str){
	printf("Name is: %s\n", *str); 	
	return 1;
}


