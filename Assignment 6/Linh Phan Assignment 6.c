//Unit6.hw******************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char upper_sorted[30];

char most_occuring_character ( char *str) {
	int i = 0;
	char str2[30] = "";
	char most;
	int next=0;
	int count = 0;
	int myCount[50];
	int len = strlen(str);

	for (i = 0; i < len; i++) {
		if (str[i] >= 'A' || str[i] <= 'Z' ) {
			str2[i] = tolower(str[i]);
		} else {
			str2[i] = str[i];
		}
	}

	for ( i =0; i < len; i++) {
		for (next = i+1; next < len; next++) {
			if ((str2[i] == str2[next]) && (str2[i] != ' ')) {
				count++;
			}
		}
		myCount[i]= count;
	}

	for (i = 1; i<len; i++) {
		if (myCount[i-1] < myCount[i]) {
			most = i;
		}
	}

	if (most > 0)
		return str[most];
	else
		return -1;
}

void count_low_up_digit ( char *str, int *lower, int *upper, int *digit) {
	int i = 0;
	int len = strlen(str);
	int lowCount = 0;
	int upCount = 0;
	int numCount = 0;

	for ( i = 0; i < len; i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			lowCount++;
		}
	}

	*lower = lowCount;

	for ( i = 0; i < len; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			upCount++;
		}
	}
	*upper = upCount;

	for ( i = 0; i < len; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			numCount++;
		}
	}
	*digit = numCount;
}

char * Up_letters ( char *str) {
	int len = strlen(str);
	int k = 0;

// Convert lowercase letters to uppercase and store in global array
	for (int i = 0; i < len; i++) {
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <=
		        'Z')) {
			upper_sorted[k++] = toupper(str[i]);
		}
	}
	upper_sorted[k] = '\0'; // Null-terminate

	// Sort the uppercase letters in the global array
	for (int i = 0; i < k - 1; i++) {
		for (int j = i + 1; j < k; j++) {
			if (upper_sorted[i] > upper_sorted[j]) {
				char temp = upper_sorted[i];
				upper_sorted[i] = upper_sorted[j];
				upper_sorted[j] = temp;
			}
		}
	}
	return upper_sorted;
}

int main() {
	char str[50] ="";
	char *upper_sorted;
	char most_occur = -1;
	int lower_case=0, upper_case=0, digits=0;

	printf("Enter your string: ");
	gets(str);

	most_occur = most_occuring_character ( str );
	if ( most_occur == -1 )
		printf ("All characters appears once\n");
	else
		printf ("The most occuring character is: %c \n", most_occur);
	count_low_up_digit ( str, &lower_case, &upper_case, &digits );
	printf ("There is/are %d lower case letter(s)\n", lower_case);
	printf ("There is/are %d upper case letter(s)\n", upper_case);
	printf ("There is/are %d digit(s)\n", digits);

	upper_sorted = Up_letters ( str );
	printf ("%s\n", upper_sorted);
	printf ("%s\n", str);
	return 0;
}
