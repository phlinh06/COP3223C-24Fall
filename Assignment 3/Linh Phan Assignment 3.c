#include <stdio.h>
#include <math.h>
#define SIZE 10

//NAMES: Linh Phan & Samantha Toole

// find: largest value, average value(float), and scan for duplicates

int main() {
	int myArray[SIZE] = {1, 56, 4, 0, -1, 5, 4, 1, 9, 78};
	int largest = myArray[0];
	int index = 0;
	float sum = 0.00;
	int dupeCount = 0;

	// finds largest value
	index = 0;
	while (index < SIZE) {
		if(myArray[index] > largest) {
			largest = myArray[index];
		}
		index++;
	}

	//AVG
	for(index = 0; index < SIZE; index++) {
		sum = myArray[index] + sum;
	}

	//dupes
	int i1, i2;
	for(i1 = 0 ; i1 < SIZE-1 ; i1++) {
		for(i2 = i1 + 1; i2 < SIZE-1 ; i2++) {
			if(myArray[i1] == myArray[i2]) {
				dupeCount++;
			}
		}
	}

	printf("1) Largest Value = %d\n", largest);
	printf("2) Average Value as a float = %.2f\n", sum/(float)SIZE);
	if (dupeCount > 0) {
		printf("3) The array has duplicates. \n");
	}
	else {
		printf("3) The array has no duplicates. \n");
	}
}
