#include "hashmap.h"
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
	enum Type kt = map->key_type, vt = map->val_type;
	if(map->slots == NULL){
		map->slots = (LinkedList**) calloc(map->nslots, sizeof(LinkedList));
	}
	ulong hash;
	if(kt == INT){
		hash = (hash / 10) % map->nslots;
	}
	else{
		hash = hash_str((char*) key) % map->nslots;
	}
	LinkedList* slot = map->slots + hash;
	Node* new_node = (Node*) malloc(sizeof(Node));
	new_node->next = NULL;
	new_node->key = key;
	new_node->value = value;
	while(slot->node != NULL){
		int duplicate;
		switch(kt){
			case INT:
			duplicate = *(int*)key == *(int*)slot->node->key;
			break;
			case CHAR:
			duplicate = *(char*)key == *(char*)slot->node->key;
			break;
			default:
			duplicate = strcmp(key, slot->node->key);
			break;
		}
		if(duplicate){
			printf("Contains a duplicate, key already in use");
			return false;
		}
		slot->node = slot->node->next;
	}
	slot->node = new_node;
	slot->size++;
	return true;
}


void debugprint_map(Map* map){
	if(map->slots == NULL) {
		printf("Map does not contain any items, vector is NULL\n");
		return;
	}

	Type keytype = map->keytype;
	Type valtype = map->valuetype;

	for(int i = 0; i < map->nslots; ++i){
		LinkedList* p = *map->slots[i];
		if(*p == 0){
			printf("LinkedList at %p is empty\n",p);
		}else{
			while(p->node != NULL){
				void* key;
				void* value;
				switch(keytype){
					case INT:
					*(int*)slot->node->key;
					break;
					case CHAR:
					duplicate = *(char*)key == *(char*)slot->node->key;
					break;
					default:
					duplicate = strcmp(key, slot->node->key);
					break;
				}
			
			}
		}
	}
}

ulong hash_str(char* str){
	ulong hash = 5381;
	int c; 
	while(c = *str){
	hash = ((hash << 5) + hash) + c;
	}
	return hash;

}




