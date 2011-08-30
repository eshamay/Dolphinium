#include <cstdio>
#include <algorithm>
#include <utility>

typedef char val_t;

// node type for the string-character tree
typedef struct node_t {
	// next = the singly-linked list for a given level of the tree
	// child = link to the next string grabbed from the tree
	// parent = link to go up for reconstructing the string
	struct node_t *next, *child, *parent;
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
std::pair<int,node> add_node (node root, node node);

