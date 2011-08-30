#include "strings.h"

void reverse_string (val_t * c, int size) {
	val_t temp;
	for (int i = 0; i < size/2; i++) {
		temp = c[i];
		c[i] = c[size-i];
		c[size-i] = temp;
	}
}

node new_root () {
	node n = new node_t;
	n->value = (val_t)NULL;
	n->next = (node)NULL;
	n->child = (node)NULL;
	n->count = 0;
	return n;
}

node new_node (char val) {
	node n = new_root();
	n->value = val;
	return n;
}

void add_node (node root, char* str, int size) {

	printf ("%c", *str);
	// see if the first char of the string is one of the children of the root
	node n = search_siblings (root->child, str[0]);

	// if the string isn't in the children, then add it in
	if (n == (node)NULL) {
		n = new_node(str[0]);
		n->next = root->child;
		root->child = n;
	}
		
	// once we have the node, if the size == 1, then increment the count
	if (size == 1)
		++n->count;
	// otherwise, we find the next level down
	else 
		add_node (n, &str[1], size - 1);
	
	return;
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


node dfs_search (node root) {


}


int main () {

	int size = 15;
	char str[20] = "caedcdebedecbed";
	//reverse_string(str,size);

	int i = 0, j = 0;
	node root = new_root();

	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			add_node (root, &str[i], j-i+1);
			printf ("\n");
		}
	}

	printf ("\ntest\n");
	print_list(root->child);
	node n = root->child;
	while (n != (node)NULL) {
		printf ("%c: %d\n", n->value, n->count);
		n = n->next;
	}
	fflush(stdout);

	return 0;
}
