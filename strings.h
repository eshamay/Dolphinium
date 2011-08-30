#include <cstdio>

typedef char val_t;

// node type for the tree
typedef struct node_t {
	struct node_t * next;
	struct node_t * child;
	val_t value;
	int count;
} node_t;
typedef node_t * node;


typedef struct int_list {
	struct int_list * next;
	int value;
} int_list;

typedef struct node_list {
	struct node_list * next;
	node value;
} node_list;



void reverse_string (val_t * c, int size);

// create a new node with the given value
node new_node (val_t val);

// given a node, search through its siblings and find a match
node search_siblings (node root, val_t val);

// add a new node into an existing tree
void add_node (node root, node node);


