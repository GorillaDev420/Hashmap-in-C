#include "genericMap.h"

#define DEFAULT_SIZE 10
#define DEFAULT_CAPACITY DEFAULT_SIZE * 2

bool _map_put(_Map** map, void* key, void* value, size_t key_size, size_t value_size){
	printf("test");
	return true;
}

	

int main(int arc, char** argv){
	printf("hello world (and Lejon)\n");
	Node** node_list = (Node**) malloc(sizeof(Node**) * DEFAULT_SIZE);
	int key = 1;
	char value[15] = "Matty Jatta <3";
	struct _Map* m = map_init(int, char*);
	map_put(&m, &key, &value);
	return 0;

}
