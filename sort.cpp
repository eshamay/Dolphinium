#include "sort.h"


void swap_int (int * left, int * right) {
	int temp = *left;
	*left = *right;
	*right = temp;
}

int partition_int_array (int * array, int start, int end, int pivot) {
   // left is the index of the leftmost element of the array
   // right is the index of the rightmost element of the array (inclusive)
   //   number of elements in subarray = right-left+1
	int pivot_value = array[pivot];
	swap_int(&array[pivot], &array[end]);
	int store_index = start;
	for (int i = start; i < end; i++) {
		if (array[i] < pivot_value) {
			swap_int(&array[i], &array[store_index]);
			++store_index;
		}
	}
	swap_int(&array[store_index], &array[end]);
	return store_index;
}

void quicksort_int_array (int * array, int start, int end) {
	if (start < end) {
		int pivot = int((start+end)/2);
		pivot = partition_int_array (array, start, end, pivot);
		quicksort_int_array (array, start, pivot - 1);
		quicksort_int_array (array, pivot+1, end);
	}
}

void print_int_array (int * array, int size) {
	for (int i = 0; i < size; i++) {
		printf ("%d ", array[i]);
	}
	printf ("\n");
	fflush(stdout);
	return;
}

// test to see if two of the array elements add up to the sum
// array must be sorted for this to work
bool find_sum (int * array, int size, int sum) {

	bool ret = false;
	int count = 0;

	int s;
	for (int i = 0; i < size-1; i++) {
		for (int j = i+1; j < size; j++) {
			s = array[i] + array[j];
			++count;
			if ( s == sum) {
				ret = true;
				break;
			} else if (s > sum) {
				break;
			}
		}
		if (ret)
			break;
	}
	printf ("%d\n", count);
	return ret;
}


int main () {

	int size = 15;
	int array[15] = {1,5,4,2,6,8,4,3,6,5,10,14,2,3,7};
	print_int_array(array, size);
	quicksort_int_array (array, 0, size-1);
	print_int_array(array, size);

	if (find_sum(array, 15, 12)) {
		printf ("found the sum!\n");
	} else {
		printf ("didn't find the sum!\n");
	}

	return 0;
}
