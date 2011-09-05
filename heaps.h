#include <cstdio>
#include <cstdlib>

typedef int val_t;
typedef val_t * val_array;
typedef int index_t;

typedef struct {
	val_array data;
	int size;
	int data_length;
} heap_t;

typedef heap_t * heap;

heap build_max_heap (val_array A, int size);
void max_heapify (heap h, index_t i);

void destroy_heap (heap h);

val_t get (heap h, index_t i);
void set (heap h, index_t i, val_t val);

val_t heap_extract_max (heap h);
void max_heap_insert (heap h, val_t v);
void heap_increase_key (heap h, index_t i, val_t v);
void swap (val_t * l, val_t * r);

int size (heap h);
void print_heap (heap h);

index_t parent (index_t i);
index_t left (index_t i);
index_t right (index_t i);
