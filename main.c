#include "hashmap.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char** argv){

	Type key = INT;
	Type value = STRING;
	Map* map = map_init(key,value,10);
	int mykey = 9;
	char[] myvalue = "Matty Lejon <3";
	if(map_put(map,&mykey,&myvalue))
}

