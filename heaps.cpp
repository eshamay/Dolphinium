#include "heaps.h"

heap build_max_heap (val_array A, int size) {
	heap h = new heap_t;

	// create the data storage in the heap
	h->data = (val_array)NULL;
	h->data = (val_array) malloc (size*sizeof(val_t));
	if (h->data == (val_array)NULL) {
		printf ("error getting memory for heap space\n");
		exit(1);
	}
	h->data_length = size;
	h->size = size;

	// Transfer the data from the incoming array to the heap
	for (int i = 0; i < h->size; i++) {
		set(h,i,A[i]);
	}

	for (int i = size/2; i >= 0; i--)
		max_heapify (h,i);

	return h;
}

void destroy_heap (heap h) {
	free(h->data);
	delete h;
	return;
}

void print_heap (heap h) {
	for (int i = 0; i < h->size; i++)
		printf ("%d  ", get(h,i));
	printf ("\n");
}

void max_heapify (heap h, index_t i) {
	index_t l = left(i);
	index_t r = right(i);
	index_t largest;
	if (l < h->size && get(h,l) > get(h,i)) {
		largest = l;
	}
	else {
		largest = i;
	}
	if (r < h->size && get(h,r) > get(h,largest)) {
		largest = r;
	}
	if (largest != i) {
		swap (&h->data[largest], &h->data[i]);
		max_heapify (h,largest);
	}
}

void swap (val_t * l, val_t * r) {
	val_t temp = *l;
	*l = *r;
	*r = temp;
	return;
}

val_t get (heap h, index_t i) {
	return h->data[i];
}

void set (heap h, index_t i, val_t val) {
	if (h->size < i) {
		printf ("out of bounds set\n");
		exit(1);
	}
	h->data[i] = val;
	return;
}

val_t get_min (heap h) {
	return get(h,0);
}

val_t get_max (heap h) {
	return get(h,0);
}

void heap_increase_key (heap h, index_t i, val_t v) {
	if (v < get(h,i)) {
		printf ("new key is smaller than the current key while trying to increase\n");
		exit(1);
	}
	set(h,i,v);

	while (i > 0 && get(h,parent(i)) < get(h,i)) {
		swap (&h->data[i], &h->data[parent(i)]);
		i = parent(i);
	}

	return;
}

val_t heap_extract_max (heap h) {
	if (h->size < 1) {
		printf ("heap underflow\n");
		exit(1);
	}
	val_t max = get(h,0);
	set(h, 0, get(h,h->size-1));
	--h->size;
	max_heapify(h,0);
	return max;
}

void max_heap_insert (heap h, val_t v) {
	// allocate new heap space if needed to insert a new key
	if (h->size == h->data_length) {
		int extra = h->size/2;
		if ((h->data = (val_array) realloc (h->data, (h->size+extra)*sizeof(val_t))) == NULL) {
			printf ("could realloc heap memory\n");
			exit(1);
		}
		h->data_length += extra;
	}

	++h->size;
	set(h,h->size-1,-65562);
	heap_increase_key(h,h->size-1,v);
	return;
}

index_t parent (index_t i) {
	return i/2;
}
index_t left (index_t i) {
	return 2*i;
}
index_t right (index_t i) {
	return 2*i+1;
}


/*
int main () {
	int array[10] = {1,4,2,5,0,3,6,9,7,8};
	heap h = build_max_heap (array, 10);

	max_heap_insert(h,16);

	while (h->size > 0) {
		printf ("%d  ", heap_extract_max(h));
	}
	printf ("\n");

	destroy_heap(h);

	return 0;
}
*/
