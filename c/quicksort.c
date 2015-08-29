/* Attribution:
*  https://github.com/fedelebron/Quicksort
*/

#include <sys/time.h>
#include "quicksort.h"
#include <stdio.h>
#include <stdlib.h>

int numbers[100000000];

void print_array(int x[], unsigned int p, unsigned int q) {
	unsigned int i;
	printf("array[%d..%d]: ", p, q);
	for(i = p; i <= q; i++) {
		printf("%d ", x[i]);
	}
	printf("\n");
}

int main() {
	int i;

	for ( i = 0; i < 100000000; i++ ) {
		numbers[i] = rand();
	}

	struct timeval stop, start;
	gettimeofday(&start, 0);
	printf("0: %d, 1: %d, 2: %d\n", numbers[0], numbers[1], numbers[2]);

	quicksort(numbers, 0, 100000000 - 1);

	gettimeofday(&stop, 0);
	printf("took %f\n", (stop.tv_sec - start.tv_sec) * 1000.0f + (stop.tv_usec - start.tv_usec) / 1000.0f);
	printf("0: %d, 1: %d, 2: %d\n", numbers[0], numbers[1], numbers[2]);
	
	return 0;
}


void swap(int* x, int* y) { 
	int temp;
	temp = *y;
	*y = *x;
	*x = temp;
}

unsigned int partition(int* array, unsigned int p, unsigned int q, unsigned int pivotLocation) {	
	int pivot;
	unsigned int i, j;
	
	pivot = array[pivotLocation];
	swap(&array[pivotLocation], &array[q]);
	i = p;
	for(j = p; j < q; j++) if(array[j] <= pivot) swap(&array[i++], &array[j]);
	swap(&array[q], &array[i]);
	return i;
}

void quicksort(int* array, unsigned int start, unsigned int end) {
	unsigned int r, pivot;
	if(start < end) {
		pivot = (end+start)/2;
		r = partition(array, start, end, pivot);
		if( r > start ) {
			quicksort(array, start, r-1);
		}
		quicksort(array, r+1, end);
	}
}