#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define SLOTS_DEFAULT_QUANTITY 10
//comment
enum Type {
	INT,
	CHAR,
	STRING
};

typedef struct{
	struct Node* next;
	void* value;
	void* key;
} Node;

typedef struct{
	Node* node;
	int64_t size;
} LinkedList;

//needs reassign for dynamic extra space allocation.
//
typedef struct{
	LinkedList** slots; //1 LL struct takes 96 bytes
	int64_t nslots;
	int64_t inserts;
	enum Type key_type;
	enum Type val_type;
} Map;


Map*  map_init(enum Type key_type, enum Type val_type,size_t init_size);
bool map_put(Map* map,void* key, void* value); 
bool map_remove(Map* map, void* key);
void debugprint_map(Map* map);
ulong hash_str(char* str);
