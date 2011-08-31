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


int find_substring_naive (char *k, int m, char *S, int n) {
	int index = -1;

	int j;
	for (int i = 0; i < n-m+1; i++) {
		for (int j = 0; j < m; j++) {
			if (S[i+j] != k[j]) break;
			if (j == m-1) index = i;
		}
		if (index != -1) break;
	}
	return index;
}

// rabin karp hash method for converting strings to decimal values
unsigned long string_to_decimal (char *s, int n) {
	unsigned long v;
	if (n == 1)
		v = (unsigned long)s[0];
	else {
		v = s[n-1] + 10*string_to_decimal(s,n-1);
	}
	return v;
}


int find_substring_rabin_karp (char *k, int m, char *S, int n) {
	int index = -1;


	return index;
}


int main () {

	char S[17] = "FDEGFBFDBDA";
	char k[3] = "BA";
	//reverse_string(S,6);

	printf ("index = %lu\n", string_to_decimal(S,11));

	fflush(stdout);

	return 0;
}
