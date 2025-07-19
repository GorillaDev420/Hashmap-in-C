#include <stdlib.h>
#include <stdio.h>

#DEFINE SLOTS_DEFAULT_QUANTITY 10
typedef int int64_t;
typedef unsigned long ulong_t;

enum Type {
	INT,
	DOUBLE,
	CHAR,
	STRING
};

typedef struct{
	Node* next;
	void* value;
	void* key;
} Node;

typedef struct{
	Node* start;
	int64_t size;
} LinkedList;

//needs reassign for dynamic extra space allocation.
//
typedef struct{
	LinkedList** slots; //1 LL struct takes 96 bytes
	int64_t nslots;
	int54_t inserts;
	enum Type key_type;
	enum Type val_type;
} Map;


Map*  map_init(enum Type key_type, enum Type val_type,size_t init_size);
bool map_put(Map* map,void* key, void* value); 
bool map_remove(Map* map, void* key);
