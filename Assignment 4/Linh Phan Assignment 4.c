#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define SIZE 10

//NAMES: Linh Phan & Samantha Toole

// UNIT 4 HW

// find: largest value, average value(float), and scan for duplicates USING POINTERS

int main() {

	int *arr;
	int *n, *i, *largest, *smallest;
	float *sum;

	//allocating memory & creating the array
	arr = malloc(SIZE * sizeof(int));
	n = malloc(sizeof(int));
	i = malloc(sizeof(int));
	sum = malloc(sizeof(float));
	largest = malloc(sizeof(int));
	smallest = malloc(sizeof(int));

	*n = SIZE;

	//1 , 56 , 4 , 0 , -1 , 5 , 4 , 1 , 9 , 78

	// sets correct values in the array
	*arr = 1;
	*( arr + 1) = 56;
	*( arr + 2) = 4;
	*( arr + 3) = 0;
	*( arr + 4) = -1;
	*( arr + 5) = 5;
	*( arr + 6) = 4;
	*( arr + 7) = 1;
	*( arr + 8) = 9;
	*( arr + 9) = 78;

	//---------------------------------------
	// finds largest value !!THIS DOES NOT WORK!!
	*i = 0;
	*largest = arr[0];
	while (*i < *n) {
		if(arr[*i] > *largest) {
			*largest = arr[*i];
		}
		*i = *i + 1;
	}

	//AVG
	*sum = 0.0;
	for(*i = 0; *i < *n; ++(*i)) {
		*sum += arr[*i];
	}

	//dupes
	int *i1, *i2, *dupeCount;
	i1 = malloc(sizeof(int));
	i2 = malloc(sizeof(int));
	dupeCount = malloc(sizeof(int));
	*dupeCount = 0;

	for(*i1 = 0 ; *i1 < *n-1 ; ++(*i1)) {
		for(*i2 = *i1 + 1; *i2 < *n-1 ; ++(*i2)) {
			if(arr[*i1] == arr[*i2]) {
				++(*dupeCount);
			}
		}
	}

	printf("1) Largest Value = %d\n", *largest);
	printf("2) Average Value as a float = %.2f\n", *sum/(float)*n);
	if (*dupeCount > 0) {
		printf("3) The array has duplicates. \n");
	}
	else {
		printf("3) The array has no duplicates. \n");
	}
}
