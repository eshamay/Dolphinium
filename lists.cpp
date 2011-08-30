#include "lists.h"

node new_node () {
	node n = new list_t;
	n->next = (node)NULL;
}

node new_node (val_t val) {
	node n = new_node();
	n->value = val;
}

node array_to_list (val_t * array, int size) {
	node n;
	if (size == 0) {
		n = (node)NULL;
	}
	else {
		n = new_node(*array);
		n->next = array_to_list(&array[1], size - 1);
	}
	return n;
}


void print_list (node root) {
	while (root != (node)NULL) {
		printf ("%d", root->value);
		root = root->next;
	}
	printf ("\n");
}


node reverse_list (node root) {
	node i = root;
	node j = root->next;
	node k;
	i->next = (node)NULL;
	while (j != (node)NULL) {
		k = j->next;
		if (k == (node)NULL)
			root = j;
		j->next = i;
		i = j;
		j = k;
	}
	return root;
}



int main () {

	int array[10] = {1,5,3,4,2,1,2,3,4,7};
	node n = array_to_list (array, 10);
	print_list (n);
	n = reverse_list(n);
	print_list (n);

	return 0;
}
