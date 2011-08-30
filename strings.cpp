#include "strings.h"

void reverse_string (val_t * c, int size) {
	val_t temp;
	for (int i = 0; i < size/2; i++) {
		temp = c[i];
		c[i] = c[size-i];
		c[size-i] = temp;
	}
}

node new_node () {
	node n = new node_t;
	n->value = (val_t)NULL;
	n->next = (node)NULL;
	n->child = (node)NULL;
	n->parent = (node)NULL;
	n->count = 0;
	return n;
}

node new_node (char val) {
	node n = new_node();
	n->value = val;
	return n;
}

std::pair<int,node> add_node (node root, char* str, int size) {

	// see if the first char of the string is one of the children of the root
	node n = search_siblings (root->child, str[0]);

	// if the string isn't in the children, then add it in as a new child of the current root level
	if (n == (node)NULL) {
		n = new_node(str[0]);
		n->next = root->child;
		n->parent = root;
		root->child = n;
	}
		
	std::pair<int,node> p;

	// once we have the node, if the size == 1, then increment the count
	if (size == 1) {
		++n->count;
		p = std::make_pair(n->count, n->child);
	}
	// otherwise, we shove it into the next level down
	else {
		p = add_node (n, &str[1], size - 1);
	}
	
	return p;
}

node add_sibling (node root, node n) {
	n->next = root;
	return n;
}

node search_siblings (node root, val_t val) {
	while (root != (node)NULL && root->value != val) {
		root = root->next;
	}
	return root;
}

void print_list (node root) {
	if (root != (node)NULL) {
		printf ("%c", root->value);
		print_list (root->next);
	}
}



int main () {

	int size = 9;
	char str[20] = "cbadeadecbadeadecbd";
	reverse_string(str,size);

	int i = 0, j = 0;
	node root = new_node();
	std::pair<int,node> p = std::make_pair(0,root), q;

	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			q = add_node (root, &str[i], j-i+1);
			if (q.first > p.first) {
				p.first = q.first;
				p.second = q.second;
			}
		}
	}

	root = p.second;
	printf ("\n");
	while (root != (node)NULL) {
		printf ("%c ", root->value);
		root = root->parent;
	}
	printf ("\n");


	fflush(stdout);

	return 0;
}
