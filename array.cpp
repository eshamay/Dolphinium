#include "array.h"

void swap (int * left, int * right) {
	val_t temp = *left;
	*left = *right;
	*right = temp;
}

void reverse_array (val_t * array, int start, int end) {
	if (start < end) {
		swap(&array[start], &array[end]);
		reverse_array (array, start+1, end-1);
	}
}

void print_array (val_t * array, int size) {
	if (size > 0) {
		printf ("%d ", *array);
		print_array (&array[1], size - 1);
	}
}

int main () {

	int temp[10] = {1,5,4,3,2,6,5,4,3,8};
	print_array (temp, 10);
	printf ("\n");
	reverse_array(temp,0,9);
	print_array (temp, 10);
	printf ("\n");

	return 0;
}
