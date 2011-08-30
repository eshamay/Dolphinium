#include <cstdio>

typedef int val_t;

typedef struct list_t {
	val_t value;
	struct list_t * next;
} list_t;
typedef list_t * node;

node new_node ();
node new_node (val_t val);
node array_to_list (val_t * array, int size);

node reverse_list (node root);

void print_int_array (int * array, int size);
