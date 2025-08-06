#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

/*
 *
 * First, have the structs have a flexible array member to store data beside the "next node";
 * We will utilize a helper function accessed by the preprocessor macro in order to pass the data size.
 * Data will be typechecked on inserts, but how does it work with many types? It should be possible to simply have several payloads.
 * The FAM will need to allocate space for both the key and value and an offset (in bytes) needs to be stored in the nodes.
 *
 *
 * */




typedef struct _Map _Map;
typedef struct Node Node;

struct _Map {
	Node** node_list;
	unsigned int capacity;
	unsigned int size;
};

struct Node {
	Node* next;
	int offset_value;
	char fam[];
};

#define Map(type0, type1) union { \
	_Map* map; \
	type0* key_type; \
	type1* value_type; \
}

#define Node(type0, type1) union { \
	Node* node; \
	type0* key_type; \
	type1* value_type; \
}

_Map*  _map_init(void* key_type, void* value_type);
#define map_init(key_type, value_type) _map_init( \
(__typeof__(*key_type)), \
(__typeof__(*value_type)))


bool _map_put(_Map** map, // maybe should be Map**????
	      void* key,
	      void* value,
	      size_t key_size,
	      size_t value_size); 

#define map_put(map, key, value) \
	_map_put(map,(1 ? (key) : (1 ? (map)->key_type : (map)->value_type)) \
	  ,sizeof(*(map)->key_type),\
	  sizeof(*(map)->value_type)) 


bool map_remove(_Map* map, void* key);
void debugprint_map(_Map* map);
long hash_str(char* str);
