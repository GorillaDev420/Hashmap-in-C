#include "hashmap.h"
#include <libcrypt.h>
#include <stdlib.h>
#include <stdio.h>

LinkedList* linkedlist_init(){

}

LinkedList** linkedlist_vector_init(enum Type key_type, enum Type val_type){

}


Map* map_init(enum Type key_type, enum Type val_type,size_t size){
	Map* this = (Map*) malloc(sizeof(Map));
	if(!this){
		perror("Malloc failed");
		exit(EXIT_FAILURE);
	}
	this->slots = NULL; //start with empty linkedList vector
	this->nslots = size;
	this->inserts = 0;
	this->key_type = key_type;
	this->val_type = val_type;
	return this;
	}

bool map_put(Map* map, void* key, void* value){
	enum Type kt = map->key_type, vt = map->value_type;
	char* str_key = (char*) key;
	int* int_key = (int*) key;
	if(map->slots == NULL){
		map->slots = (LinkedList**) calloc(sizeof(LinkedList) * map->size);
	}
	ulong_t hash;
	if(kt == STRING || kt == CHAR){
		hash = hash_str((char*) key) % map->size;
	}
	else{
		hash = (hash / 10) % map->size;
	}
	LinkedList* slot = map->slots + hash;
	Node* new_node = (Node*) malloc(sizeof(Node));
	new_node->key = key;
	new_node->value = value;
	while(slot->node != NULL){
		slot->node = slot->node->next;
	}
	slot->size++;

}

ulong_t hash_str(char* s){
	ulong_t hash = 5381;
	int c; 
	while(c = *str){
	hash = ((hash << 5) + hash) + c;
	}
	return hash;

}


}


