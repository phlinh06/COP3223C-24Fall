//unit2.hw
//Linh Phan

#include <stdio.h>
#include <ctype.h>

int main() {
	float hwScore;
	float projectScore;
	float labScore;
	float midterm1Score;
	float midterm2Score;
	float finalScore;
	char answer = 'y';
	int counter = 0, counter2 = 0, counter3 = 0, counter4 = 0, counter5 = 0, counter6 = 0, counter7 = 0;

	while (answer == 'y') {
		while (answer == 'y') {
			counter = 0;
			printf("\nEnter the hw average score:");
			scanf(" %f", &hwScore);
			while ((hwScore < 0 || hwScore > 100) && counter != 2) {
				printf("Invalid score. Try again:");
				scanf("%f",&hwScore);
				counter++;
			}
			if (counter == 2) {
				break;
			}

			counter2 = 0;
			printf("\nEnter the project average score:");
			scanf(" %f", &projectScore);
			while ((projectScore < 0 || projectScore > 100) && counter2 != 2) {
				printf("Invalid score. Try again:");
				scanf("%f",&projectScore);
				counter2++;
			}
			if (counter2 == 2 && (projectScore < 0 || projectScore > 100)) {
				break;
			}

			counter3 = 0;
			printf("\nEnter the lab average score:");
			scanf(" %f", &labScore);
			while ((labScore < 0 || labScore > 100) && counter3 != 2) {
				printf("Invalid score. Try again:");
				scanf("%f",&labScore);
				counter3++;
			}
			if (counter3 == 2) {
				break;
			}

			counter4 = 0;
			counter5 = 0;
			counter6 = 0;
			printf("\nEnter the midterm1, midterm2, and finals score:");
			scanf(" %f %f %f", &midterm1Score, &midterm2Score, &finalScore);

			while ((midterm1Score < 0 || midterm1Score > 100) && counter4 != 2) {
				printf("Invalid midterm1 score. Try again:");
				scanf("%f",&midterm1Score);
				counter4++;
			}
			if (counter4 == 2) {
				break;
			}

			while ((midterm2Score < 0 || midterm2Score > 100) && counter5 != 2) {
				printf("Invalid midterm2 score. Try again:");
				scanf("%f",&midterm2Score);
				counter5++;
			}
			if (counter5 == 2) {
				break;
			}

			while ((finalScore < 0 || finalScore > 100) && counter6 != 2) {
				printf("Invalid final score. Try again:");
				scanf("%f",&finalScore);
				counter6++;
			}
			if (counter6 == 2) {
				break;
			}
			float grade = 0.2*(hwScore) + 0.2*(projectScore) + 0.05*(labScore) + (midterm1Score + midterm2Score + finalScore) *.55/3;
			if (counter != 3 &&counter2 != 3 &&counter3 != 3 &&counter4 != 3 &&counter5 != 3 &&counter6 != 3) {
				printf("Here are all of your average test scores: \n");
				printf("\tHW:\t\t%.2f\n", hwScore);
				printf("\tPROJECTS:\t%.2f\n", projectScore);
				printf("\tLABS:\t\t%.2f\n", labScore);
				printf("\tMIDTERM1:\t%.2f\n", midterm1Score);
				printf("\tMIDTERM2:\t%.2f\n", midterm2Score);
				printf("\tFINAL:\t\t%.2f\n", finalScore);
				printf("--------------------\n");
				printf("OVERALL GRADE:\t %.2f\n", grade);
				printf("(0.2*(%.2f) + 0.2*(%.2f) + 0.05*(%.2f) + (%.2f + %.2f + %.2f) *.55/3 is %.2f)\n", hwScore, projectScore, labScore, midterm1Score, midterm2Score, finalScore, grade);
				printf("---------------------\n");

				char letterGrade;
				char letter;
				if(grade >= 94.00) {
					letterGrade = 'A';
					letter = ' ';
				}
				else if (grade < 94.00 && grade >= 90.00) {
					letterGrade = 'A'; //ISSUE
					letter = '-';
				}
				else if (grade < 90.00 && grade >= 87.00) {
					letterGrade = 'B';
					letter = '+';
				}
				else if (grade < 87.00 && grade >= 84.00) {
					letterGrade = 'B';
					letter = ' ';
				}
				else if (grade < 84.00 && grade >= 80.00) {
					letterGrade = 'B';
					letter = '-';
				}
				else if (grade < 80.00 && grade >= 77.00) {
					letterGrade = 'C';
					letter = '+';
				}
				else if (grade < 77.00 && grade >= 74.00) {
					letterGrade = 'C';
					letter = ' ';
				}
				else if (grade < 74.00 && grade >= 70.00) {
					letterGrade = 'C';
					letter = '-';
				}
				else if (grade < 70.00 && grade >= 67.00) {
					letterGrade = 'D';
					letter = '+';
				}
				else if (grade < 67.00 && grade >= 64.00) {
					letterGrade = 'D';
					letter = ' ';
				}
				else if (grade < 64.00 && grade >= 61.00) {
					letterGrade = 'D';
					letter = '-';
				}
				else {
					letterGrade = 'F';
					letter = ' ';
				}
				printf("\n\n\tFinal Letter Grade: %c%c\n", letterGrade, letter);
				break;
			}
		}
		if (counter < 2 && counter2 < 2 && counter3 < 2 && counter4 < 2 && counter5 < 2 && counter6 < 2) {
			answer == 'n';
		}
		if (counter == 2 || counter2 == 2 || counter3 == 2 || counter4 == 2 || counter5 == 2|| counter6 ==2) {
			printf("\nI'm sorry... You tried too many time.");
		}
		printf("\n\n");
		printf("Would you like to start over?(Y/N) ");
		scanf("\n %c", &answer);
		printf("\n\n");
		answer = tolower(answer);
		while (answer!= 'n' && answer!= 'y' && counter7 < 2) {
			printf("Invalid character. Try again.: ");
			scanf("\n %c", &answer);
			answer = tolower(answer);
			counter7++;
		}

		if (answer == 'y') {
			answer == 'y';
			counter7=0;
			printf("*************");
		}
		else if (answer == 'n') {
			printf("\n\tGoodbye!\n\n");
		}
		else if(counter7 == 2 && (answer != 'y'|| answer!='n')) {
			printf("\n\tPROGRAM TERMINATED.\n\n");
			return 0;
		}

	}
	return 0;
}
